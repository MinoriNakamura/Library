#include<d3d9.h>

void InitPresentParameters(HWND hWnd);


class InitDirectX {
public:
	LPDIRECT3D9 pD3d;
	D3DPRESENT_PARAMETERS D3dPresentParameters;
};