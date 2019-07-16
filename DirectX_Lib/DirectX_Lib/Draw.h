#pragma once

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する

#include <windows.h>
#include <d3d9.h>

VOID Draw(float x, float y, float z, float rhw, DWORD color, float tu, float tv, float width, float height, float tu_width, float tv_height, int texture_number);

struct CUSTOMVERTEX {
	float	x, y, z;	// 頂点座標
	float	rhw;	// 除算数
	DWORD	Color;	// 頂点の色
	float	tu, tv;	//　テクスチャ座標
};

class Texture {
public:
	LPDIRECT3DTEXTURE9 pTexture;
};


