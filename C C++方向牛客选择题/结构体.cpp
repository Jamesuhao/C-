#if 0
#1
��������˵���Ͷ�����䣺
union uti{ int n; double g; char ch[9]; } struct srt { float xy; union uti uv; }aa; 
�����ڴ���룬�����aa��ռ�ڴ���ֽ�����(24)
ע�⣺����int��float��4�ֽڣ�double��8�ֽڣ�char��1�ֽڡ� 
union����������Ա����ռ䣬Ӧ����char��9�ݣ�ռ9�ֽڣ�Ȼ����8�ֽ�Ϊ��λ���룬����utiʵ��ռ16�ֽڡ� 
struct srt�У�����4 + 16��20�ֽڣ�ͬ����8�ֽڶ��룬����Ӧ����24
#endif