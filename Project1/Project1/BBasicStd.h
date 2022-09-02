#ifndef BBASIC_STD
#define BBASIC_STD

/*********************<�˸�>*************************************
*  �� ������ �⺻������ ���Ǵ� ������ϰ� �ʿ��� ��ġ���� ����		*
* �صδ� �����Դϴ�.												*
*****************************************************************/

#include <Windows.h>
#include <tchar.h>
#include <math.h>
#include <string>
#include <ctime>
#include <map>    //�� �����ϴµ� ���
#include <list> //�Ѿ�, �� �� �Ŵ�¡�ϴµ� ���
#include <stack>
#include <vector>
#include <queue> //�ִϸ��̼� ť �ϴµ� ���
#include <memory>

#define BASIC_WINDOW_NAME _T("FRAMEWORK ENGINE")
#define PI 3.141592654

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

//��������� winnm.lib ������ �߰��Ѵ�.
#pragma comment(lib, "winmm.lib")

using namespace std;

typedef struct tagFPOINT
{
	float x;
	float y;
} FPOINT;

typedef struct tagOBJECTSIZE
{
	int width;
	int height;
} OBJECTSIZE;

typedef struct SeqPoint
{
	float time;
	float angle;
} SeqPoint;

enum class ENEMY_TYPE
{
	ENEMY_01 = 0,
	ENEMY_02 = 1,
	ENEMY_03 = 2,
	ENEMY_04 = 3,
	ENEMY_BOSS = 4
};

#endif // !BBASIC_STD