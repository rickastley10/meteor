#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdlib.h>

/* ============================================================
   CONFIG
   ============================================================ */
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

/* ============================================================
   GLOBALS
   ============================================================ */
static HBITMAP backbuffer_bitmap;
static HDC backbuffer_dc;
static void* backbuffer_memory;
static BITMAPINFO backbuffer_info;
static int running = 1; /* 1 = running, 0 = exit */

/* ============================================================
   RENDERER
   ============================================================ */
void clear_screen(uint32_t color)
{
    int i;
    uint32_t* pixel = (uint32_t*)backbuffer_memory;
    for (i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
        pixel[i] = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color)
{
    int px, py, sx, sy;
    for (py = 0; py < h; py++)
    {
        sy = y + py;
        if (sy < 0 || sy >= WINDOW_HEIGHT) continue;

        for (px = 0; px < w; px++)
        {
            sx = x + px;
            if (sx < 0 || sx >= WINDOW_WIDTH) continue;

            ((uint32_t*)backbuffer_memory)[sy * WINDOW_WIDTH + sx] = color;
        }
    }
}

/* ============================================================
   WINDOW
   ============================================================ */
LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_CLOSE || msg == WM_DESTROY)
    {
        running = 0;
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

/* ============================================================
   BACKBUFFER
   ============================================================ */
void init_backbuffer(HWND hwnd)
{
    HDC window_dc;
    window_dc = GetDC(hwnd);
    backbuffer_dc = CreateCompatibleDC(window_dc);

    /* Initialize bitmap info */
    memset(&backbuffer_info, 0, sizeof(backbuffer_info));
    backbuffer_info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    backbuffer_info.bmiHeader.biWidth = WINDOW_WIDTH;
    backbuffer_info.bmiHeader.biHeight = -WINDOW_HEIGHT; /* top-down */
    backbuffer_info.bmiHeader.biPlanes = 1;
    backbuffer_info.bmiHeader.biBitCount = 32;
    backbuffer_info.bmiHeader.biCompression = BI_RGB;

    backbuffer_bitmap = CreateDIBSection(
        window_dc,
        &backbuffer_info,
        DIB_RGB_COLORS,
        &backbuffer_memory,
        NULL,
        0
    );

    SelectObject(backbuffer_dc, backbuffer_bitmap);
    ReleaseDC(hwnd, window_dc);
}

/* ============================================================
   MAIN LOOP
   ============================================================ */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prev, LPSTR cmd, int show)
{
    WNDCLASS wc;
    HWND hwnd;
    MSG msg;
    HDC window_dc;

    int rect_x, rect_y;

    /* Register window class */
    memset(&wc, 0, sizeof(wc));
    wc.lpfnWndProc = window_proc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Minimal2DEngine";
    RegisterClass(&wc);

    /* Create window */
    hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        "Minimal 2D Engine",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, hInstance, NULL
    );

    init_backbuffer(hwnd);

srand(time(NULL));   // Seed once at program start


int px=200, py=300;
/*
400x400
200 = center / 0
150 = -50
0 = -200
400 = 200
*/
int m1x=(rand()%20+1)*20,m1y=((rand()%10+1)*20);
int m2x=(rand()%20+1)*20,m2y=((rand()%10+1)*20);
int m3x=(rand()%20+1)*20,m3y=((rand()%10+1)*20);
int m4x=(rand()%20+1)*20,m4y=((rand()%10+1)*20);
int m5x=(rand()%20+1)*20,m5y=((rand()%10+1)*20);
int m6x=(rand()%20+1)*20,m6y=((rand()%10+1)*20);
int m7x=(rand()%20+1)*20,m7y=((rand()%10+1)*20);
int m8x=(rand()%20+1)*20,m8y=((rand()%10+1)*20);
int m9x=(rand()%20+1)*20,m9y=((rand()%10+1)*20);
int m10x=(rand()%20+1)*20,m10y=((rand()%10+1)*20);
int w=20;int h=20;
int score=0,count=0;
    /* ============================================================
   MAIN LOOP
   ============================================================ */
while (running)
{
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // ===== PADDLE CONTROLS =====
    if (GetAsyncKeyState('D') & 0x8000) {
        if(px<400){px=px+w;}
    }
    if (GetAsyncKeyState('A') & 0x8000) {
        if(px>0){px=px-w;}
    }

    /* Example draw */
    clear_screen(0xFFFFFFFF); /* white background */
    /*
    red - 0xFFFF0000
    orange - 0xFFFFA500
    black - 0xFF000000
    */
    /*x y w h colour*/
    draw_rect(px, py, w, h, 0xFF000000);

    draw_rect(m1x, m1y, w, h, 0xFFFFA500);
    draw_rect(m1x, m1y - h, w, h, 0xFFFF0000);

    draw_rect(m2x, m2y, w, h, 0xFFFFA500);
    draw_rect(m2x, m2y - h, w, h, 0xFFFF0000);

    draw_rect(m3x, m3y, w, h, 0xFFFFA500);
    draw_rect(m3x, m3y - h, w, h, 0xFFFF0000);

    draw_rect(m4x, m4y, w, h, 0xFFFFA500);
    draw_rect(m4x, m4y - h, w, h, 0xFFFF0000);

    draw_rect(m5x, m5y, w, h, 0xFFFFA500);
    draw_rect(m5x, m5y - h, w, h, 0xFFFF0000);

    draw_rect(m6x, m6y, w, h, 0xFFFFA500);
    draw_rect(m6x, m6y - h, w, h, 0xFFFF0000);

    draw_rect(m7x, m7y, w, h, 0xFFFFA500);
    draw_rect(m7x, m7y - h, w, h, 0xFFFF0000);

    draw_rect(m8x, m8y, w, h, 0xFFFFA500);
    draw_rect(m8x, m8y - h, w, h, 0xFFFF0000);

    draw_rect(m9x, m9y, w, h, 0xFFFFA500);
    draw_rect(m9x, m9y - h, w, h, 0xFFFF0000);

    draw_rect(m10x, m10y, w, h, 0xFFFFA500);
    draw_rect(m10x, m10y - h, w, h, 0xFFFF0000);

    m1y=m1y+h;if(m1y==400+h){m1y=0;m1x=(rand()%20+1)*20;count=count+1;}
    m2y=m2y+h;if(m2y==400+h){m2y=0;m2x=(rand()%20+1)*20;count=count+1;}
    m3y=m3y+h;if(m3y==400+h){m3y=0;m3x=(rand()%20+1)*20;count=count+1;}
    m4y=m4y+h;if(m4y==400+h){m4y=0;m4x=(rand()%20+1)*20;count=count+1;}
    m5y=m5y+h;if(m5y==400+h){m5y=0;m5x=(rand()%20+1)*20;count=count+1;}
    m6y=m6y+h;if(m6y==400+h){m6y=0;m6x=(rand()%20+1)*20;count=count+1;}
    m7y=m7y+h;if(m7y==400+h){m7y=0;m7x=(rand()%20+1)*20;count=count+1;}
    m8y=m8y+h;if(m8y==400+h){m8y=0;m8x=(rand()%20+1)*20;count=count+1;}
    m9y=m9y+h;if(m9y==400+h){m9y=0;m9x=(rand()%20+1)*20;count=count+1;}
    m10y=m10y+h;if(m10y==400+h){m10y=0;m10x=(rand()%20+1)*20;count=count+1;}
    if(count>=10){score=score+1;count=0;}
    if((px==m1x&&py==m1y)||(px==m2x&&py==m2y)||(px==m3x&&py==m3y)||(px==m4x&&py==m4y)||(px==m5x&&py==m5y)||(px==m6x&&py==m6y)||(px==m7x&&py==m7y)||(px==m8x&&py==m8y)||(px==m9x&&py==m9y)||(px==m10x&&py==m10y)){m1x=(rand()%20+1)*20,m1y=((rand()%10+1)*20);m2x=(rand()%20+1)*20,m2y=((rand()%10+1)*20);m3x=(rand()%20+1)*20,m3y=((rand()%10+1)*20);m4x=(rand()%20+1)*20,m4y=((rand()%10+1)*20);m5x=(rand()%20+1)*20,m5y=((rand()%10+1)*20);m6x=(rand()%20+1)*20,m6y=((rand()%10+1)*20);m7x=(rand()%20+1)*20,m7y=((rand()%10+1)*20);m8x=(rand()%20+1)*20,m8y=((rand()%10+1)*20);m9x=(rand()%20+1)*20,m9y=((rand()%10+1)*20);m10x=(rand()%20+1)*20,m10y=((rand()%10+1)*20);}
    
    /* Flip backbuffer */
    window_dc = GetDC(hwnd);
    BitBlt(window_dc, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, backbuffer_dc, 0, 0, SRCCOPY);
    ReleaseDC(hwnd, window_dc);

    Sleep(100); // 16ms ~ 60 FPS
}


    return 0;
}