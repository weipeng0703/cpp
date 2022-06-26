// 分别给出BOOL，int，float，指针变量 与“零值”比较的 if 语句（假设变量名为var）

/*
BOOL型变量：if(!var)   
int型变量： if(var == 0)   
float型变量：   
const float EPSINON = 0.00001;   
if ((x >= - EPSINON) && (x <= EPSINON)   
指针变量：　　if(var == NULL)   
*/