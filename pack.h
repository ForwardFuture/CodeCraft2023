#pragma once

#include "Global.h"
#include "desk.h"
#include "car.h"

struct seed_c
{
	int seed = 0;
	int seeds[5] = { 0,352354535,350895017,351758063,350804994 };
	int seed_MOD = 998244353;
}seed_class;

struct desk_c
{
	int cnt_desk;
	Desk desk[52];
	bool is_corner[52];
	vector <int > total_desk[10];

	void init_desk();
}desk_class;

struct map_c
{
	int num_desk_7;
	int num_desk_9;
	char map[N][N];							// ��ͼ
	double dis1[52][N][N];					// ��������̨����ͼ��ĳ�������С���루С����û����Ʒ��
	double dis2[52][N][N];					// ��������̨����ͼ��ĳ�������С���루С��������Ʒ��

	void dij(int desk_num);
	void get_dis();
}map_class;

struct car_c
{
	bool available_car[4] = { 0,0,0,0 }; // stop_frame ǰת�� stop_frame ��ʱ��С�����б�ǡ�
}car_class;

struct constant_c
{
	double Earning[10] = { 0,3000,3200,3400,7100,7800,8300,29000 };
	int money;
	int frame_number;
	int son[10][2];
	vector <int > father[10];			// son �� father �����˹���̨֮���������Ϣ���� init �г�ʼ��
}constant_class;

struct wait_c
{
	bool is_waiting_for_7[10];							//ĳ����Ʒ��С�����������͵��ߺŵĹ�����
	bool wait[4] = { 0,0,0,0 };							//��ǰС���͵������һ��ԭ�ϣ����ǵ�ǰ��Ʒ��û����������
	bool wait_until_spare_3[4] = { 0,0,0,0 };			//��ǰС����ԭ�� 1-3 ʱ������ 1-3 ��û��������
	bool wait_until_spare_7[4] = { 0,0,0,0 };			//��ǰС���ڵ�һ����ߣ�׼����ȡ��Ʒʱ����û�ط��͵��µȴ�
	bool wait_until_spare_sell[4] = { 0,0,0,0 };		//��ǰС����Ҫ������Ʒ������û�취�������µȴ������Ż�����
	bool wait_stop_frame[4] = { 0,0,0,0 };				//stop_frame ����ĵȴ�
}wait_class;

struct math_c
{
	double dddis1(int desk1, int desk2);
	double cddis1(int car1, int desk1);
	double dddis2(int desk1, int desk2);
	double cddis2(int car1, int desk1);
}math_class;

struct occupied_c
{
	int occupied[52][10];					// ����̨�Ƿ�ռ��
	int sol_occupied[52][10];				// �Ƿ�������̨��ռ��
	int occupied_goods[10];					// ����ĳ����Ʒ������
	int occupied_stop_frame[52][10];		// stop_frame ��� occupied
	int sol_occupied_stop_frame[52][10];    // stop_frame ��� sol_occupied
	int ignore_occupied[52][10];			// ignore occupied �Ӷ���������������
	bool sol_ignore_occupied[52][10];		// ��� ignore occupied
	int current_occupied[52][10];			// ������ check_spare_7 �õ�����ʱ������������ʶ�Ƿ�ռ����һ�� 7

	void reload_occupied();					// ÿ֡�� reload occupied��ocuupied ����ռ��ʱ���Ա�֡ռ�ã����ǽ��ʱ������һ֡���
}occupied_class;

struct assist_c
{
	bool full_6(int desk_num, int goods); //��ǰ��Ʒ�͵����ж� 4-6 �Ź���̨�ǲ����Ѿ�����
	bool full_7(int dest, int goods);	 //��ǰ��Ʒ�͵����ж� 7 �Ź���̨�ǲ����Ѿ�����
	bool check_spare_7(int type);		//��ǰ�Ƿ��п��е� 7 �Ź���̨
}assist_class;

struct command_c
{
	bool init_dc;
	int destination[5];                 // С���ڵ�ǰʱ���Ŀ�ĵ�
	queue <int > total_destination[5];  // С�������ϴξ��ߺ������Ŀ�ĵ���
	int buy[5];                         // 1 Ϊ buy,0 Ϊ sel
	queue <int > total_buy[5];          // С�������ϴξ��ߺ������ buy ��
	int check[5];						// С����ǰ�Ƿ� check һ���Ƿ�����Ʒ
	queue <int > total_check[5];		// С���ܵ� check ��

	// Sel ����С��ȥ��������Buy ����
	void Sel(int car_num, int desk_num, int Check = 0);
	void Buy(int car_num, int desk_num, int Check = 0);
	void clear_decision(int k);

	bool md[4] = { 0,0,0,0 };
	bool md_7[4] = { 0,0,0,0 };
	bool md_9[4] = { 0,0,0,0 };
	bool md_stop_frame[4] = { 0,0,0,0 };
}command_class;


struct parameter_c
{
	int Stop_frame = 14500;
	double Time_Upscale = 1.2;
	double Earning_Upscale = 1.2;
	double End_frame = 14950;
	double fun1_desk_exist_num_downscale = 1;//1 - δ��Ȩ   0 - ���й���̨�ϵ� 4/5/6 ��Ʒ������
	double dis_pow_downscale = 5;

	void adjust_fun();
	double fun1(double remain, int type = 0);
	double fun2(bool output_is_ready, int output_is_doing, bool is_begin_now);
	double fun3(bool is_begin);
	double fun4(int current_frame, double distance, bool is_7, bool is_done);
	double fun5(bool is_7, bool is_empty, bool is_done, double is_doing, int desk_num, int goods);
	double fun6(int desk_num, int number_of_exists);
}parameter_class;

