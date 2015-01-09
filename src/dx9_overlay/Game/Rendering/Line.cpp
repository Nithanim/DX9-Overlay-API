#include "Line.h"

CLine::CLine(CRenderer *renderer, int x1,int y1,int x2,int y2,int width,D3DCOLOR color, bool bShow)
	: CRenderBase(renderer), m_Line(NULL)
{
	SetPos(x1,y1,x2,y2);
	SetWidth(width);
	SetColor(color);
	SetShown(bShow);
}

void CLine::SetPos(int x1,int y1,int x2,int y2)
{
	m_X1 = x1, m_X2 = x2;
	m_Y1 = y1, m_Y2 = y2;
}

void CLine::SetWidth(int width)
{
	m_Width = width;
}

void CLine::SetColor(D3DCOLOR color)
{
	m_Color = color;
}

void CLine::SetShown(bool show)
{
	m_bShow = show;
}

void CLine::Draw(IDirect3DDevice9 *pDevice)
{
	if(!m_bShow || m_Line == NULL)
		return;

	D3DVIEWPORT9 view;
	pDevice->GetViewport(&view);

	D3DXVECTOR2	LinePos[2];

	m_Line->SetAntialias(TRUE);
	m_Line->SetWidth((FLOAT)m_Width);

	m_Line->Begin();

	LinePos[0].x = m_X1;
	LinePos[0].y = m_Y1;
	LinePos[1].x = m_X2;
	LinePos[1].y = m_Y2;

	m_Line->Draw(LinePos,2,m_Color);
	m_Line->End();	
}

void CLine::Reset(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->OnLostDevice();
		m_Line->OnResetDevice();
	}
}

void CLine::Show()
{
	SetShown(true);
}

void CLine::Hide()
{
	SetShown(false);
}

void CLine::ReleaseResourcesForDeletion(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->Release();
		m_Line = NULL;
	}
}

bool CLine::CanBeDeleted()
{
	return (m_Line == NULL) ? true : false;
}

bool CLine::LoadResource(IDirect3DDevice9 *pDevice)
{
	if(m_Line)
	{
		m_Line->Release();
		m_Line = NULL;
	}

	D3DXCreateLine(pDevice,&m_Line);

	return m_Line != NULL;
}

void CLine::FirstDrawAfterReset(IDirect3DDevice9 *pDevice)
{

}