/*
参数不合法的判别条件不完整。合法的入口参数条件为：(0<i≤a.length) && (0≤k≤a.length-i+1)
删除元素低效;
改为:

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
