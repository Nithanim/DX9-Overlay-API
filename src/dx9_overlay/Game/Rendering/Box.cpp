#include "Box.h"
#include "dx_utils.h"

CBox::CBox(CRenderer *renderer,  int x, int y, int w, int h, D3DCOLOR color, bool show) : CRenderBase(renderer), m_bShown(false)
{
	SetPos(x, y);
	SetBoxWidth(w);
	SetBoxHeight(h);
	SetBoxColor(color);
	SetShown(show);

	SetBoxColor(color);
	SetBorderWidth(0);
	SetBorderShown(false);
}


void CBox::SetPos(int x,int y)
{
	m_iX = x, m_iY = y;
}

void CBox::SetBorderColor(D3DCOLOR dwColor)
{
	m_dwBorderColor = dwColor;
}

void CBox::SetBoxColor(D3DCOLOR dwColor)
{
	m_dwBoxColor = dwColor;
}

void CBox::SetBorderWidth(DWORD dwWidth)
{
	m_dwBorderWidth = dwWidth;
}

void CBox::SetBoxWidth(DWORD dwWidth)
{
	m_dwBoxWidth = dwWidth;
}

void CBox::SetBoxHeight(DWORD dwHeight)
{
	m_dwBoxHeight = dwHeight;
}

void CBox::SetBorderShown(bool b)
{
	m_bBorderShown = b;
}

void CBox::SetShown(bool b)
{
	m_bShown = b;
}

void CBox::Draw(IDirect3DDevice9 *pDevice)
{
	if(!m_bShown)
		return;

	D3DVIEWPORT9 view;
	RECT box; 

	pDevice->GetViewport(&view);

	Drawing::DrawBox(m_iX, m_iY, m_dwBoxWidth, m_dwBoxHeight, m_dwBoxColor, pDevice);

	if(m_bBorderShown)
		Drawing::DrawRectangular(m_iX, m_iY, m_dwBoxWidth, m_dwBoxHeight, m_dwBorderWidth, m_dwBorderColor, pDevice);
}

void CBox::Reset(IDirect3DDevice9 *pDevice)
{
	
}

void CBox::Show()
{
	SetShown(true);
}

void CBox::Hide()
{
	SetShown(false);
}

void CBox::ReleaseResourcesForDeletion(IDirect3DDevice9 *pDevice)
{
	m_bShown = false;
	m_bBorderShown = false;
}

bool CBox::CanBeDeleted()
{
	return true;
}

bool CBox::LoadResource(IDirect3DDevice9 *pDevice)
{
	return true;
}

void CBox::FirstDrawAfterReset(IDirect3DDevice9 *pDevice)
{
	
}