// DirectX_Lib.cpp : スタティック ライブラリ用の関数を定義します。
//

#include "pch.h"
#include "Draw.h"

VOID Draw(float x,float y,float z,float rhw,DWORD color,float tu,float tv,float width,float height,float tu_width,float tv_height,int texture,DirectX directx)
{
	CUSTOMVERTEX v[4] =
	{
	{x        , y         , z, rhw, color, tu           , tv		    },
	{x + width, y         , z, rhw, color, tu + tu_width, tv            },
	{x + width, y + height, z, rhw, color, tu + tu_width, tv + tv_height},
	{x        , y + height, z, rhw, color, tu           , tv + tv_height}
	};

	directx.pD3Device->BeginScene();

	directx.pD3Device->SetTexture(0, directx.pTexture[texture]);
	
	directx.pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, v, sizeof(CUSTOMVERTEX));

	directx.pD3Device->EndScene();

	directx.pD3Device->Present(0, 0, 0, 0);
}