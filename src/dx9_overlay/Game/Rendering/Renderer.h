#pragma once
#include <d3dx9.h>

#include <boost/container/map.hpp>

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

class CRenderBase;

class CRenderer
{
	typedef boost::shared_ptr<CRenderBase> SharedRenderObject;
	typedef boost::container::map<int, SharedRenderObject> RenderObjects;

public:
	int  Add(SharedRenderObject Object);

	bool Remove(int id);

	template<typename T> boost::shared_ptr<T> Get(int id)
	{
		if(_RenderObjects.empty())
			return nullptr;

		if(_RenderObjects.find(id) == _RenderObjects.end())
			return nullptr;

		if(_RenderObjects[id]->_isMarkedForDeletion)
			return nullptr;

		return boost::dynamic_pointer_cast<T, CRenderBase>(_RenderObjects[id]);
	}

	void Draw(IDirect3DDevice9 *pDevice);
	void Reset(IDirect3DDevice9 *pDevice);

	void ShowAll();
	void HideAll();
	void DestroyAll();

	int GetFrameRate() const;

	int GetScreenWidth() const;
	int GetScreenHeight() const;

	boost::mutex& RenderMutex() 
	{ 
		return _mtx;
	}

private:
	int _frameRate;
	int _width;
	int _height;

	static RenderObjects	_RenderObjects;
	static boost::mutex		_mtx;
};

