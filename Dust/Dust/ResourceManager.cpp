#include "ResourceManager.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include "Material.h"
#include "Texture2D.h"
#include "Mesh.h"
#include "Font.h"
#include "SceneManager.h"
#include "Debug.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

using namespace boost::filesystem;
using namespace std;

ResourceManager::ResourceManager()
{
	_resources = std::map<unsigned long, Resource*>();

	Awake();
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::Awake()
{
	string root_path = "..\\Resources";

	if (!exists(root_path))
	{
		Debug::Warning("Resource Folder does not exist!");
		return;
	}

	FindResources(root_path);
}

void ResourceManager::ShutDown()
{
	for (auto itr = _resources.begin(); itr != _resources.end(); ++itr)
	{
		if (itr->second->IsLoaded())
			itr->second->Unload();
		delete itr->second;
	}
	_resources.clear();
}

void ResourceManager::FindResources(string dirPath)
{
	Debug::Message("Folder Found: " + dirPath);
	directory_iterator endItr;
	string currPath;
	for (directory_iterator itr(dirPath); itr != endItr; ++itr)
	{
		currPath = itr->path().string();
		if (is_directory(itr->status()))
			FindResources(currPath);
		else if (currPath.substr(currPath.length() - 5) != ".meta")
		{
			Debug::Message("Resource Found: " + currPath);
			//Get File Data
			string metaPath = currPath + ".meta";
			if (!exists(metaPath))
			{
				Debug::Warning("Meta Missing: " + currPath);
				continue;
			}

			vector<string> data = ReadFile(metaPath);

			//Choose Type
			string ext = path(currPath).extension().string();
			Resource* resource = 0;
			//Material
			if (ext == ".mat")
			{
				resource = new Material();
				resource->SetType(Resource_Material);
				resource->SetPath(stows(currPath));

				for (unsigned int l = 0; l < data.size(); ++l)
				{
					vector<string> tokens = GetTokens(data[l], ' ');
					for (unsigned int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == "_guid:")
						{
							resource->SetResourceID(stoul(tokens[++i]));
						}
					}
				}
			}
			//Texture2D
			else if (ext == ".dds")
			{
				resource = new Texture2D();
				resource->SetType(Resource_Texture);
				resource->SetPath(stows(currPath));

				for (unsigned int l = 0; l < data.size(); ++l)
				{
					vector<string> tokens = GetTokens(data[l], ' ');
					for (unsigned int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == "_guid:")
						{
							resource->SetResourceID(stoul(tokens[++i]));
						}
					}
				}
			}
			//Mesh
			//Obj
			else if (ext == ".obj")
			{
				resource = new Mesh();
				resource->SetType(Resource_Mesh);
				resource->SetPath(stows(currPath));

				for (unsigned int l = 0; l < data.size(); ++l)
				{
					vector<string> tokens = GetTokens(data[l], ' ');
					for (unsigned int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == "_guid:")
						{
							resource->SetResourceID(stoul(tokens[++i]));
						}
					}
				}
			}
			//Font
			else if (ext == ".font")
			{
				resource = new Font();
				resource->SetType(Resource_Font);
				resource->SetPath(stows(currPath));

				for (unsigned int l = 0; l < data.size(); ++l)
				{
					vector<string> tokens = GetTokens(data[l], ' ');
					for (unsigned int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == "_guid:")
						{
							resource->SetResourceID(stoul(tokens[++i]));
						}
					}
				}
			}
			//Scene
			else if (ext == ".scene")
			{
				Scene* scene = new Scene();
				scene->SetPath(stows(currPath));

				for (unsigned int l = 0; l < data.size(); ++l)
				{
					vector<string> tokens = GetTokens(data[l], ' ');
					for (unsigned int i = 0; i < tokens.size(); ++i)
					{
						if (tokens[i] == "_index:")
						{
							scene->SetIndex(stoul(tokens[++i]));
						}
					}
				}

				SceneManager::getInstance().AddScene(scene->GetIndex(), scene);
			}

			if (resource)
				_resources.insert(pair<unsigned long, Resource*>(resource->GetResourceID(), resource));
			resource = 0;
		}
	}
}

Resource* ResourceManager::GetResource(unsigned long id)
{
	Resource* r = 0;
	r = _resources.find(id)->second;
	//TODO: If did not find
	if (!r->IsLoaded())
		r->Load();
	return r;
}