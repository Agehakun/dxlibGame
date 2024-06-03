#include "Dxlib.h"//Dxライブラリーをインクルード（読み込み）

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);

    //DxLIｂの初期化処置
    if (DxLib_Init() == -1)
    {
        //エラーが起きたら直ちに終了
        return -1;
    }
    //円の初期位置
    int circleX = 200;
    int circleY = 150;
    int stringX = 10;
    int stringY = 15;
    int stringX1 = 10;
    int stringY1 = 45;
    int mouseX = 10;
    int mouseY = 15;

    //円の色指定
    int circleColor = GetColor(0, 0, 255);
    //文字の色指定
    int StringColor = GetColor(255, 255, 255);
    int StringColor2 = GetColor(255, 0, 0);
    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
   //画面の初期化
        ClearDrawScreen();
        //文字の大きさの指定
        SetFontSize(32);
        //画面の文字表示
        //DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //画面に円を描画させる
        DrawCircle(circleX,circleY,30,GetColor(0,0,255),TRUE);
        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);
        //マウスがクリックされたら
        if ((GetMouseInput() & MOUSE_INPUT_LEFT))
        {
            SetFontSize(30);
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }
        //テンキーの上を押せば上に動く
        if(CheckHitKey(KEY_INPUT_UP))
    if (CheckHitKey(KEY_INPUT_W)|| CheckHitKey(KEY_INPUT_UP))
    {
        if (circleY <= 40)
        {
            circleY += 3;
        }
        else
        {
            circleY -= 3;
        }
    }
    if (CheckHitKey(KEY_INPUT_S)|| CheckHitKey(KEY_INPUT_DOWN))
    {
        if (circleY >= 560)
        {
            circleY -= 3;
        }
        else
        {
            circleY += 3;
        }
    }
    if (CheckHitKey(KEY_INPUT_A)|| CheckHitKey(KEY_INPUT_LEFT))
    {
        if (circleX <= 40)
        {
            circleX += 3;
        }
        else
        {
            circleX -= 3;
        }
    }
    if (CheckHitKey(KEY_INPUT_D)|| CheckHitKey(KEY_INPUT_RIGHT))
    {
        if (circleX >= 740)
        {
            circleX -= 3;
        }
        else
        {
            circleX += 3;
        }
    }
    //円のX座標に動きをつける
   /* circleX += 90;
    circleY += 80;
    if (circleX >= 800)
    {
        circleX = 0;
        circleY = 0;
    }*/
    //表画面の内容を表画面に反映させる
    ScreenFlip();
    }
     

    //画面に点を描画させてね。（Ｘ座標，Ｙ座標，点の色を指定）
    DrawCircle(320, 240,30,GetColor(0, 0, 255),TRUE);
    //キー入力待ち
    WaitKey();
    //Gxlib使用の終了
    DxLib_End();
    //ソースの終了
    return 0;


}
