#include "stdafx.h"
#include <iostream>

using namespace std;

//*****************************����������������ͺ���֮���ת��*****************************begin

//��������ת��Ϊ��������
//����˵����  (in)   pre       ��������  ��������
//           (out)  post      ��������  ��������
//           (in)   preLow    ��������  ����ĵ�һ�������±�
//           (in)   preHigh   ��������  ��������һ�������±�
//           (in)   postLow   ��������  ����ĵ�һ�������±�
//           (in)   postHigh  ��������  ��������һ�������±�
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

//��������ת��Ϊ��������
//����˵����  (out)  pre       ��������  ��������
//           (in)   post      ��������  ��������
//           (in)   preLow    ��������  ����ĵ�һ�������±�
//           (in)   preHigh   ��������  ��������һ�������±�
//           (in)   postLow   ��������  ����ĵ�һ�������±�
//           (in)   postHigh  ��������  ��������һ�������±�
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

//��������ת��Ϊ��������
//����˵����  (in)  pre       ��������  ��������
//           (out)  mid       ��������  ��������
//           (in)   preLow    ��������  ����ĵ�һ�������±�
//           (in)   preHigh   ��������  ��������һ�������±�
//           (in)   midLow    ��������  ����ĵ�һ�������±�
//           (in)   midHigh   ��������  ��������һ�������±�
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

//��������ת��Ϊ��������
//����˵����  (out)  pre       ��������  ��������
//           (in)   mid       ��������  ��������
//           (in)   preLow    ��������  ����ĵ�һ�������±�
//           (in)   preHigh   ��������  ��������һ�������±�
//           (in)   midLow    ��������  ����ĵ�һ�������±�
//           (in)   midHigh   ��������  ��������һ�������±�
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

//��������ת��Ϊ��������
//����˵����  (in)  post       ��������  ��������
//           (out)  mid       ��������  ��������
//           (in)   postLow   ��������  ����ĵ�һ�������±�
//           (in)   postHigh  ��������  ��������һ�������±�
//           (in)   midLow    ��������  ����ĵ�һ�������±�
//           (in)   midHigh   ��������  ��������һ�������±�
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

//��������ת��Ϊ��������
//����˵����  (out)  post      ��������  ��������
//           (in)   mid       ��������  ��������
//           (in)   postLow   ��������  ����ĵ�һ�������±�
//           (in)   postHigh  ��������  ��������һ�������±�
//           (in)   midLow    ��������  ����ĵ�һ�������±�
//           (in)   midHigh   ��������  ��������һ�������±�
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

//*****************************����������������ͺ���֮���ת��*****************************end

int _tmain(int argc, _TCHAR* argv[])
{
    int Pre[15] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
    int PreChangeToMid[15] = {0};
    int PreChangeToPost[15] = {0};
    cout<<"**************************ǰ��ת��Ϊ����**************************"<<endl<<endl;
    PreToMid(Pre, PreChangeToMid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PreChangeToMid[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************ǰ��ת��Ϊ����**************************"<<endl<<endl;
    PreToPost(Pre, PreChangeToPost, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PreChangeToPost[i]<<"    ";
    }

    int Mid[15] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
    int MidChangeToPre[15] = {0};
    int MidChangeToPost[15] = {0};
    cout<<endl;
    cout<<endl<<"**************************����ת��Ϊǰ��**************************"<<endl<<endl;
    MidToPre(MidChangeToPre, Mid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<MidChangeToPre[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************����ת��Ϊ����**************************"<<endl<<endl;
    MidToPost(MidChangeToPost, Mid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<MidChangeToPost[i]<<"    ";
    }

    int Post[15] = {8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
    int PostChangeToPre[15] = {0};
    int PostChangeToMid[15] = {0};
    cout<<endl;
    cout<<endl<<"**************************����ת��Ϊǰ��**************************"<<endl<<endl;
    PostToPre(PostChangeToPre, Post, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PostChangeToPre[i]<<"    ";
    }
    cout<<endl;
    cout<<endl<<"**************************����ת��Ϊ����**************************"<<endl<<endl;
    PostToMid(Post, PostChangeToMid, 0, 14, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout<<PostChangeToMid[i]<<"    ";
    }

    cout<<endl;
    return 0;
}
