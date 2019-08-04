#include "stdafx.h"
#include <iostream>

using namespace std;

//*****************************满二叉树先序、中序和后序之间的转换*****************************begin

//先序序列转换为后序序列
//参数说明：  (in)   pre       ————  先序数组
//           (out)  post      ————  后序数组
//           (in)   preLow    ————  先序的第一个结点的下标
//           (in)   preHigh   ————  先序的最后一个结点的下标
//           (in)   postLow   ————  后序的第一个结点的下标
//           (in)   postHigh  ————  后序的最后一个结点的下标
void PreToPost(int pre[], int post[], int preLow, int preHigh, int postLow, int postHigh)
{
    if (preHigh >= preLow)
    {
        post[postHigh] = pre[preLow];
        int tmp = (preHigh - preLow) / 2;
        PreToPost(pre, post, preLow + 1, preLow + tmp, postLow, postLow + tmp - 1);
        PreToPost(pre, post, preLow + tmp + 1, preHigh, postLow + tmp, postHigh - 1);
    }
}

//后序序列转换为先序序列
//参数说明：  (out)  pre       ————  先序数组
//           (in)   post      ————  后序数组
//           (in)   preLow    ————  先序的第一个结点的下标
//           (in)   preHigh   ————  先序的最后一个结点的下标
//           (in)   postLow   ————  后序的第一个结点的下标
//           (in)   postHigh  ————  后序的最后一个结点的下标
void PostToPre(int pre[], int post[], int preLow, int preHigh, int postLow, int postHigh)
{
    if (postHigh >= postLow)
    {
        pre[preLow] = post[postHigh];
        int tmp = (postHigh - postLow) / 2;
        PostToPre(pre, post, preLow + 1, preLow + tmp, postLow, postLow + tmp - 1);
        PostToPre(pre, post, preLow + tmp + 1, preHigh, postLow + tmp, postHigh - 1);
    }
}

//先序序列转换为中序序列
//参数说明：  (in)  pre       ————  先序数组
//           (out)  mid       ————  中序数组
//           (in)   preLow    ————  先序的第一个结点的下标
//           (in)   preHigh   ————  先序的最后一个结点的下标
//           (in)   midLow    ————  中序的第一个结点的下标
//           (in)   midHigh   ————  中序的最后一个结点的下标
void PreToMid(int pre[], int mid[], int preLow, int preHigh, int midLow, int midHigh)
{
    if (preHigh >= preLow)
    {
        mid[(midHigh + midLow) / 2] = pre[preLow];
        int tmp = (preHigh - preLow) / 2;
        PreToMid(pre, mid, preLow + 1, preLow + tmp, midLow, midLow + tmp - 1);
        PreToMid(pre, mid, preLow + tmp + 1, preHigh, midLow + tmp + 1, midHigh);
    }
}

//中序序列转换为先序序列
//参数说明：  (out)  pre       ————  先序数组
//           (in)   mid       ————  后序数组
//           (in)   preLow    ————  先序的第一个结点的下标
//           (in)   preHigh   ————  先序的最后一个结点的下标
//           (in)   midLow    ————  中序的第一个结点的下标
//           (in)   midHigh   ————  中序的最后一个结点的下标
void MidToPre(int pre[], int mid[], int preLow, int preHigh, int midLow, int midHigh)
{
    if (midHigh >= midLow)
    {
        int tmp = (midHigh - midLow) / 2;
        pre[preLow] = mid[(midHigh + midLow) / 2];
        MidToPre(pre, mid, preLow + 1, preLow + tmp, midLow, midLow + tmp - 1);
        MidToPre(pre, mid, preLow + tmp + 1, preHigh, midLow + tmp + 1, midHigh);
    }
}

//后序序列转换为中序序列
//参数说明：  (in)  post       ————  后序数组
//           (out)  mid       ————  中序数组
//           (in)   postLow   ————  后序的第一个结点的下标
//           (in)   postHigh  ————  后序的最后一个结点的下标
//           (in)   midLow    ————  中序的第一个结点的下标
//           (in)   midHigh   ————  中序的最后一个结点的下标
void PostToMid(int post[], int mid[], int midLow, int midHigh, int postLow, int postHigh)
{
    if (postHigh >= postLow)
    {
        mid[(midHigh + midLow) / 2] = post[postHigh];
        int tmp = (postHigh - postLow) / 2;
        PostToMid(post, mid, midLow, midLow + tmp - 1, postLow, postLow + tmp - 1);
        PostToMid(post, mid, midLow + tmp + 1, midHigh, postLow + tmp, postHigh - 1);
    }
}

//中序序列转换为后序序列
//参数说明：  (out)  post      ————  后序数组
//           (in)   mid       ————  中序数组
//           (in)   postLow   ————  后序的第一个结点的下标
//           (in)   postHigh  ————  后序的最后一个结点的下标
//           (in)   midLow    ————  中序的第一个结点的下标
//           (in)   midHigh   ————  中序的最后一个结点的下标
void MidToPost(int post[], int mid[], int midLow, int midHigh, int postLow, int postHigh)
{
    if (midHigh >= midLow)
    {
        post[postHigh] = mid[(midHigh + midLow) / 2];
        int tmp = (midHigh - midLow) / 2;
        MidToPost(post, mid, midLow, midLow + tmp - 1, postLow, postLow + tmp - 1);
        MidToPost(post, mid, midLow + tmp + 1, midHigh, postLow + tmp, postHigh - 1);
    }
}

//*****************************满二叉树先序、中序和后序之间的转换*****************************end

int _tmain(int argc, _TCHAR* argv[])
{
    int Pre[15] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    int PreChangeToMid[15] = {0};
    int PreChangeToPost[15] = {0};
    cout<<"**************************前序转换为中序**************************"<<endl<<endl;
    PreToMid(Pre, PreChangeToMid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PreChangeToMid[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************前序转换为后序**************************"<<endl<<endl;
    PreToPost(Pre, PreChangeToPost, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PreChangeToPost[i]<<"    ";
    }

    int Mid[15] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    int MidChangeToPre[15] = {0};
    int MidChangeToPost[15] = {0};
    cout<<endl;
    cout<<endl<<"**************************中序转换为前序**************************"<<endl<<endl;
    MidToPre(MidChangeToPre, Mid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<MidChangeToPre[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************中序转换为后序**************************"<<endl<<endl;
    MidToPost(MidChangeToPost, Mid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<MidChangeToPost[i]<<"    ";
    }

    int Post[15] = {8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
    int PostChangeToPre[15] = {0};
    int PostChangeToMid[15] = {0};
    cout<<endl;
    cout<<endl<<"**************************后序转换为前序**************************"<<endl<<endl;
    PostToPre(PostChangeToPre, Post, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PostChangeToPre[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************后序转换为中序**************************"<<endl<<endl;
    PostToMid(Post, PostChangeToMid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PostChangeToMid[i]<<"    ";
    }

    cout<<endl;
    return 0;
}
