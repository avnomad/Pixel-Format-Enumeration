//	Copyright (C) 2011-2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of Pixel Format Enumeration.
 *
 *	Pixel Format Enumeration is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Pixel Format Enumeration is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Pixel Format Enumeration.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::clog;
using std::left;
using std::right;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <cstdlib>
using std::system;
using std::exit;

#include <GL/glew.h>
#include <GL/glut.h>

#include <windows.h>
#include <tchar.h>

void printPixelFormat(const PIXELFORMATDESCRIPTOR &pfd,unsigned int indent,unsigned int width1,unsigned int width2);

int main()
{
	WNDCLASS soleWindowClass;
	soleWindowClass.style = CS_HREDRAW|CS_VREDRAW;
	soleWindowClass.lpfnWndProc = DefWindowProc;
	soleWindowClass.cbClsExtra = 0;
	soleWindowClass.cbWndExtra = 0;
	soleWindowClass.hInstance = GetModuleHandle(nullptr);
	soleWindowClass.hIcon = nullptr;	// can be null
	soleWindowClass.hCursor = nullptr;	// can be null
	soleWindowClass.hbrBackground = nullptr;
	soleWindowClass.lpszMenuName = nullptr;
	soleWindowClass.lpszClassName = _T("EnumeratePixelFormatsClass");
	RegisterClass(&soleWindowClass);

	PIXELFORMATDESCRIPTOR pixelFormatDescription;
	int pixelFormatIndex;
	int maxPixelFormatIndex;
	HDC gdiContext;

	cout << setw(6) << ' ' << "Copyright (C) 2011-2012  Vaptistis Anogeianakis\n\n";
	cout << setw(6) << ' ' << "This program comes with ABSOLUTELY NO WARRANTY.\n";
    cout << setw(6) << ' ' << "This is free software, and you are welcome to\n";
	cout << setw(6) << ' ' << "redistribute it under certain conditions.\n";
	cout << setw(6) << ' ' << "See license.txt for details.\n\n\n";

	cout << setw(4) << ' ' << "Available pixel formats:\n\n";

	HWND window = CreateWindow(_T("EnumeratePixelFormatsClass"),nullptr,WS_OVERLAPPEDWINDOW,0,0,0,0,nullptr,nullptr,GetModuleHandle(nullptr),nullptr);
	gdiContext = GetDC(window);
		// enumerate supported pixel formats.
		maxPixelFormatIndex = DescribePixelFormat(gdiContext,0,0,nullptr);	// will return 0 on failure
		for(pixelFormatIndex = 1 ; pixelFormatIndex <= maxPixelFormatIndex ; ++pixelFormatIndex)
		{
			cout << "Format " << pixelFormatIndex << '\n';
			DescribePixelFormat(gdiContext,pixelFormatIndex,sizeof(PIXELFORMATDESCRIPTOR),&pixelFormatDescription);
			printPixelFormat(pixelFormatDescription,4,16,8);
		} // end for
		cout << endl;
	ReleaseDC(window,gdiContext);
	DestroyWindow(window);

	system("pause");
	return 0;
} // end function main

void printPixelFormat(const PIXELFORMATDESCRIPTOR &pfd,unsigned int indent,unsigned int width1,unsigned int width2)
{
	cout << left << setw(indent) << ' ' << setw(width1) << "nSize" << right << setw(width2) << (unsigned int)pfd.nSize << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "nVersion" << right << setw(width2) << (unsigned int)pfd.nVersion << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "dwFlags" << right << setw(width2) << (unsigned int)pfd.dwFlags << '\n';
	if(pfd.dwFlags & PFD_DRAW_TO_WINDOW)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_DRAW_TO_WINDOW" << '\n';
	if(pfd.dwFlags & PFD_DRAW_TO_BITMAP)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_DRAW_TO_BITMAP" << '\n';
	if(pfd.dwFlags & PFD_SUPPORT_GDI)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_SUPPORT_GDI" << '\n';
	if(pfd.dwFlags & PFD_SUPPORT_OPENGL)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_SUPPORT_OPENGL" << '\n';
	if(pfd.dwFlags & PFD_GENERIC_ACCELERATED)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_GENERIC_ACCELERATED" << '\n';
	if(pfd.dwFlags & PFD_GENERIC_FORMAT)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_GENERIC_FORMAT" << '\n';
	if(pfd.dwFlags & PFD_NEED_PALETTE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_NEED_PALETTE" << '\n';
	if(pfd.dwFlags & PFD_NEED_SYSTEM_PALETTE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_NEED_SYSTEM_PALETTE" << '\n';
	if(pfd.dwFlags & PFD_DOUBLEBUFFER)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_DOUBLEBUFFER" << '\n';
	if(pfd.dwFlags & PFD_STEREO)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_STEREO" << '\n';
	if(pfd.dwFlags & PFD_SWAP_LAYER_BUFFERS)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_SWAP_LAYER_BUFFERS" << '\n';
	if(pfd.dwFlags & PFD_DEPTH_DONTCARE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_DEPTH_DONTCARE" << '\n';
	if(pfd.dwFlags & PFD_DOUBLEBUFFER_DONTCARE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_DOUBLEBUFFER_DONTCARE" << '\n';
	if(pfd.dwFlags & PFD_STEREO_DONTCARE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_STEREO_DONTCARE" << '\n';
	if(pfd.dwFlags & PFD_SWAP_COPY)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_SWAP_COPY" << '\n';
	if(pfd.dwFlags & PFD_SWAP_EXCHANGE)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_SWAP_EXCHANGE" << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "iPixelType" << right << setw(width2) << (unsigned int)pfd.iPixelType << '\n';
	if((pfd.iPixelType & 0x1) == PFD_TYPE_RGBA)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_TYPE_RGBA" << '\n';
	if(pfd.iPixelType & PFD_TYPE_COLORINDEX)
		cout << right << setw(indent+width1+width2) << ' ' << "PFD_TYPE_COLORINDEX" << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cColorBits" << right << setw(width2) << (unsigned int)pfd.cColorBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cRedBits" << right << setw(width2) << (unsigned int)pfd.cRedBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cRedShift" << right << setw(width2) << (unsigned int)pfd.cRedShift << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cGreenBits" << right << setw(width2) << (unsigned int)pfd.cGreenBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cGreenShift" << right << setw(width2) << (unsigned int)pfd.cGreenShift << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cBlueBits" << right << setw(width2) << (unsigned int)pfd.cBlueBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cBlueShift" << right << setw(width2) << (unsigned int)pfd.cBlueShift << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAlphaBits" << right << setw(width2) << (unsigned int)pfd.cAlphaBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAlphaShift" << right << setw(width2) << (unsigned int)pfd.cAlphaShift << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAccumBits" << right << setw(width2) << (unsigned int)pfd.cAccumBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAccumRedBits" << right << setw(width2) << (unsigned int)pfd.cAccumRedBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAccumGreenBits" << right << setw(width2) << (unsigned int)pfd.cAccumGreenBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAccumBlueBits" << right << setw(width2) << (unsigned int)pfd.cAccumBlueBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAccumAlphaBits" << right << setw(width2) << (unsigned int)pfd.cAccumAlphaBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cDepthBits" << right << setw(width2) << (unsigned int)pfd.cDepthBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cStencilBits" << right << setw(width2) << (unsigned int)pfd.cStencilBits << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "cAuxBuffers" << right << setw(width2) << (unsigned int)pfd.cAuxBuffers << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "iLayerType" << right << setw(width2) << (unsigned int)pfd.iLayerType << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "bReserved" << right << setw(width2) << (unsigned int)pfd.bReserved << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "dwLayerMask" << right << setw(width2) << (unsigned int)pfd.dwLayerMask << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "dwVisibleMask" << right << setw(width2) << (unsigned int)pfd.dwVisibleMask << '\n';
	cout << left << setw(indent) << ' ' << setw(width1) << "dwDamageMask" << right << setw(width2) << (unsigned int)pfd.dwDamageMask << '\n';
	cout << '\n';
} // end function 