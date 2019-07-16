#include "InitDirectX.h"
#include "pch.h"
#include "DirectX.h"

HRESULT InitD3d(HWND hWnd, InitDirectX initdirectx, DirectX directx)
{
	//Direct３Dオブジェクトの作成
	if (NULL == (initdirectx.pD3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3Dの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}

	InitPresentParameters(hWnd,false,0,0,initdirectx);

	if (FAILED(initdirectx.pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&initdirectx.D3dPresentParameters, &directx.pD3Device/*ダブルポインタ*/)))
	{
		MessageBox(0, "HALモードでDIRECT3Dデバイスを作成できません\nREFモードｄで再試行します", NULL, MB_OK);
		if (FAILED(initdirectx.pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hWnd,
			D3DCREATE_MIXED_VERTEXPROCESSING,
			&initdirectx.D3dPresentParameters, &directx.pD3Device)))
		{
			MessageBox(0, "DIRECT3Dデバイスの作成に失敗しました", NULL, MB_OK);
			return E_FAIL;
		}
	}
	return S_OK;
}
void InitPresentParameters(HWND hWnd, bool windowed, int screen_width, int screen_height, InitDirectX initdirectx) {
	//WindowMode
	ZeroMemory(&initdirectx.D3dPresentParameters, sizeof(D3DPRESENT_PARAMETERS));
	initdirectx.D3dPresentParameters.BackBufferWidth = screen_width;
	initdirectx.D3dPresentParameters.BackBufferHeight = screen_height;
	initdirectx.D3dPresentParameters.BackBufferFormat = D3DFMT_UNKNOWN;
	initdirectx.D3dPresentParameters.BackBufferCount = 1;
	initdirectx.D3dPresentParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
	initdirectx.D3dPresentParameters.MultiSampleQuality = 0;
	initdirectx.D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	initdirectx.D3dPresentParameters.hDeviceWindow = hWnd;
	initdirectx.D3dPresentParameters.Windowed = windowed;
	initdirectx.D3dPresentParameters.EnableAutoDepthStencil = FALSE;
	initdirectx.D3dPresentParameters.AutoDepthStencilFormat = D3DFMT_A1R5G5B5;
	initdirectx.D3dPresentParameters.Flags = 0;
	initdirectx.D3dPresentParameters.FullScreen_RefreshRateInHz = 0;
	initdirectx.D3dPresentParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}