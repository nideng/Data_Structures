/*
�������Ϸ����б��������������Ϸ�����ڲ�������Ϊ��(0<i��a.length) && (0��k��a.length-i+1)
ɾ��Ԫ�ص�Ч;
��Ϊ:

Status DeleteK(SqList&a,int i,int k)
{

if(i<1||k<0||i+k-1>a.length) return INFEASIBLE;
else
{
for(int j=i;j<=i+k-1;j++)
a.elem[j-1]=a.elem[j];
}
a.lenth-=k;
return OK;
}



*/
