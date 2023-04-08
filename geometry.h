#pragma once


//����/��ѧ
pair<double, double> getVec(double);                                                                                   // �õ�ָ���Ӧ�Ƕȵĵ�λ����
double Sign(double);                                                                                                   // ��ȡ��������ķ���
double Dot(double, double, double, double);                                                                            // ����������ʽ��
double Dot(pair<double, double>, pair<double, double>);                                                                // �����������ʽ��
double Cross(double, double, double, double);                                                                          // ����������ʽ��
double Cross(pair<double, double>, pair<double, double>);                                                              // �����������ʽ��
pair<double, double> Rotate(pair<double, double>, double);                                                             // ��ת����
pair<double, double> multi(pair<double, double>, double);                                                              // �����˱���
pair<double, double> Add(pair<double, double>, pair<double, double>);                                                  // ����������
pair<double, double> Sub(pair<double, double>, pair<double, double>);                                                  // ����������
double Dist(double, double, double, double);                                                                           // ����������֮��ľ��루double�����ʽ��
double Dist(pair<double, double>, pair<double, double>);                                                               // ����������֮��ľ��루pair��ʽ��
double PointToLine(pair<double, double>, pair<double, double>, pair<double, double>);                                  // ����㵽ֱ�߾���
double PointToSegment(pair<double, double>, pair<double, double>, pair<double, double>);                               // ����㵽�߶ξ���
bool SegmentCross(pair<double, double>, pair<double, double>, pair<double, double>, pair<double, double>);             // �ж��߶��Ƿ��ཻ
pair<double, double> CrossPoint(pair<double, double>, pair<double, double>, pair<double, double>, pair<double, double>);// ֱ���󽻵�
void AdjuAng(double&);                                                                                                 // �����Ƕȷ�Χʹ������-Pi��Pi֮��
double CombineV(double, double);                                                                                       // ������ٶȣ������ʽ���Ǹ���
double CombineV(pair<double, double>);                                                                                 // ������ٶȣ�������ʽ���Ǹ���
void UnitV(pair<double, double>&);                                                                                     // ��λ������