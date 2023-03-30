#pragma once
#include "Global.h"
#include "desk.h"

namespace seed_n
{
	static int seed = 0;
	static int seeds[5] = { 0,352354535,350895017,351758063,350804994 };
	static int seed_MOD = 998244353;
}

namespace map_n
{
	static int num_desk_7;
	static int num_desk_9;
	static char map[N][N];							// ��ͼ
	static double dis[2][52][N][N];					
	static bool can_not_move[2][8][N][N];			// 0�� 1�J 2�� 3�K 4�� 5�L 6�� 7�I

	static bool is_MAX(int type,int desk_num,int x,int y);
	static void dij(int desk_num,int type);
	static void get_dis(int type);
	static void init_wall();
	static void init_desk();
}

namespace desk_n
{
	static int cnt_desk;
	static Desk desk[52];
	static bool can_not_sell[52];
	static vector <int > total_desk[10];
	static void init_desk();
}

namespace car_n
{
	static bool available_car[4] = { 0,0,0,0 }; // stop_frame ǰת�� stop_frame ��ʱ��С�����б�ǡ�
}

namespace constant_n
{
	static double Earning[10] = { 0,3000,3200,3400,7100,7800,8300,29000 };
	static int money;
	static int frame_number;
	static int son[10][2];
	static vector <int > father[10];			// son �� father �����˹���̨֮���������Ϣ���� init �г�ʼ��
}

namespace wait_n
{
	static bool is_waiting_for_7[10];							//ĳ����Ʒ��С�����������͵��ߺŵĹ�����
	static bool wait[4] = { 0,0,0,0 };							//��ǰС���͵������һ��ԭ�ϣ����ǵ�ǰ��Ʒ��û����������
	static bool wait_until_spare_3[4] = { 0,0,0,0 };			//��ǰС����ԭ�� 1-3 ʱ������ 1-3 ��û��������
	static bool wait_until_spare_7[4] = { 0,0,0,0 };			//��ǰС���ڵ�һ����ߣ�׼����ȡ��Ʒʱ����û�ط��͵��µȴ�
	static bool wait_until_spare_sell[4] = { 0,0,0,0 };		//��ǰС����Ҫ������Ʒ������û�취�������µȴ������Ż�����
	static bool wait_stop_frame[4] = { 0,0,0,0 };				//stop_frame ����ĵȴ�
}

namespace math_n
{
	static int otoe(double x);									// ���굽���ӱ�ŵ�ӳ�䣨ֻԼ�֣������ֺ��ݣ�
	static pair <int, int > dtoe(int desk_num);					// ����̨��ŵ����ӱ�ŵ�ӳ��
	static pair <int, int > ctoe(int car_num);					// С����ŵ����ӱ�ŵ�ӳ��
	static double dddis1(int desk1, int desk2);					// ĳ������̨����һ������̨��û���ö����ľ���
	static double cddis1(int car1, int desk1);					// ĳ��С����ĳ������̨��û���ö����ľ���
	static double dddis2(int desk1, int desk2);					// ĳ������̨����һ������̨���ö����ľ���
	static double cddis2(int car1, int desk1);					// ĳ��С����ĳ������̨���ö����ľ���
}

namespace occupied_n
{
	static int occupied[52][10];					// ����̨�Ƿ�ռ��
	static int sol_occupied[52][10];				// �Ƿ�������̨��ռ��
	static int occupied_goods[10];					// ����ĳ����Ʒ������
	static int occupied_stop_frame[52][10];		// stop_frame ��� occupied
	static int sol_occupied_stop_frame[52][10];    // stop_frame ��� sol_occupied
	static int ignore_occupied[52][10];			// ignore occupied �Ӷ���������������
	static bool sol_ignore_occupied[52][10];		// ��� ignore occupied
	static int current_occupied[52][10];			// ������ check_spare_7 �õ�����ʱ������������ʶ�Ƿ�ռ����һ�� 7

	static void reload_occupied();					// ÿ֡�� reload occupied��ocuupied ����ռ��ʱ���Ա�֡ռ�ã����ǽ��ʱ������һ֡���
}

namespace assist_n
{
	static bool full_6(int desk_num, int goods); //��ǰ��Ʒ�͵����ж� 4-6 �Ź���̨�ǲ����Ѿ�����
	static bool full_7(int dest, int goods);	 //��ǰ��Ʒ�͵����ж� 7 �Ź���̨�ǲ����Ѿ�����
	static bool check_spare_7(int type);		//��ǰ�Ƿ��п��е� 7 �Ź���̨
}

namespace command_n
{
	static bool init_dc;
	static int destination[5];                 // С���ڵ�ǰʱ���Ŀ�ĵ�
	static queue <int > total_destination[5];  // С�������ϴξ��ߺ������Ŀ�ĵ���
	static int buy[5];                         // 1 Ϊ buy,0 Ϊ sel
	static queue <int > total_buy[5];          // С�������ϴξ��ߺ������ buy ��
	static int check[5];						// С����ǰ�Ƿ� check һ���Ƿ�����Ʒ
	static queue <int > total_check[5];		// С���ܵ� check ��

	// Sel ����С��ȥ��������Buy ����
	static void Sel(int car_num, int desk_num, int Check = 0);
	static void Buy(int car_num, int desk_num, int Check = 0);
	static void clear_decision(int k);

	static bool md[4] = { 0,0,0,0 };
	static bool md_7[4] = { 0,0,0,0 };
	static bool md_9[4] = { 0,0,0,0 };
	static bool md_stop_frame[4] = { 0,0,0,0 };
}

namespace parameter					//������
{
	static int Stop_frame = 14500;
	static double Time_Upscale = 1.2;
	static double Earning_Upscale = 1.2;
	static double End_frame = 14950;
	static double fun1_desk_exist_num_downscale = 1;//1 - δ��Ȩ   0 - ���й���̨�ϵ� 4/5/6 ��Ʒ������
	static double dis_pow_downscale = 5;

	static void adjust_fun();
	static double fun1(double remain, int type = 0);
	static double fun2(bool output_is_ready, int output_is_doing, bool is_begin_now);
	static double fun3(bool is_begin);
	static double fun4(int current_frame, double distance, bool is_7, bool is_done);
	static double fun5(bool is_7, bool is_empty, bool is_done, double is_doing, int desk_num, int goods);
	static double fun6(int desk_num, int number_of_exists);
}

using namespace seed_n;				//���Ӱ�
using namespace map_n;				//��ͼ��
using namespace constant_n;			//������
using namespace wait_n;				//�ȴ���
using namespace occupied_n;			//ռ�ð�
using namespace command_n;			//ָ���
using namespace desk_n;				//������	
using namespace math_n;				//��ѧ��
using namespace car_n;				//С����
using namespace assist_n;			//Э����
