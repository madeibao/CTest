#include <iostream>
#include<stack> 
using namespace std;
 
 
//区分判断表达式中的操作数和操作符
bool IsOperator(char ch)  
{  
    if (ch == '+' || ch == '-' ||  
        ch == '*' || ch == '/' ||  
        ch == '(' || ch == ')' || ch == '#')  
        return true;  
    else  
        return false;  
          
}  
//运算符的优先关系  
                         //'+', '-', '*', '/', '(', ')', '#'    
char OprRelation[7][7] = {{'>', '>', '<', '<', '<', '>', '>'}, //'+'   
                          {'>', '>', '<', '<', '<', '>', '>'}, //'-'   
                          {'>', '>', '>', '>', '<', '>', '>'}, //'*'   
                          {'>', '>', '>', '>', '<', '>', '>'}, //'/'   
                          {'<', '<', '<', '<', '<', '=', '>'}, //'('   
                          {'>', '>', '>', '>', '=', '>', '>'}, //')'   
                          {'<', '<', '<', '<', '<', ' ', '='}};//'#'   
 
//将运算符转化为数组下标以便进行优先级比较
int ConvertToIndex(char opr)  
{  
    int index;  
  
    switch (opr)  
    {  
    case '+':  
        index = 0;  
        break;  
    case '-':  
        index = 1;  
        break;  
    case '*':  
        index = 2;  
        break;  
    case '/':  
        index = 3;  
        break;  
    case '(':  
        index = 4;  
        break;  
    case ')':  
        index = 5;  
        break;  
    case '#':  
        index = 6;  
        break;  
    }  
  
    return index;  
}  
  
//运算符优先级比较
char Precede(char opr1, char opr2)  
{  
    int index1 = ConvertToIndex(opr1);  
    int index2 = ConvertToIndex(opr2);  
  
    return OprRelation[index1][index2];  
}  
 
//进行运算符转化
int Operate(int opnd1, char op, int opnd2)  
{  
    int ret;  
  
    switch(op)  
    {  
    case '+':  
        ret = opnd1 + opnd2;  
        break;  
    case '-':  
        ret = opnd1 - opnd2;  
        break;  
    case '*':  
        ret = opnd1 * opnd2;  
        break;  
    case '/':  
        ret = opnd1 / opnd2;  
        break;  
    }  
  
    return ret;  
}  
  
//运算符优先算法  
int CaculateExpression(string exp)  
{  
    stack<char> optr; //只处理+ - # / ()运算  
    stack<int> opnd;   
    char ch;  
    int i = 0;  
      
    exp += "#";  
    optr.push('#');  
      
    ch = exp[i++];  
      
    //如果##配对，表达式求值完成  
    while (ch != '#' || optr.top() != '#')  
    {  
        if (!IsOperator(ch))  
        {  
            //操作数入栈  
			int a=0;
			while(!IsOperator(ch))
			{
			 a=a*10+ch-'0';       //将String转化为int
			 ch=exp[i++];
			}
            opnd.push(a);  
         
        }  
        else  
        {  
            //比较栈顶操作符和新取得的操作符的优先关系  
            switch (Precede(optr.top(), ch))  
            {  
            case '<'://栈顶优先权低  
                optr.push(ch);  
                ch = exp[i++];  
                break;  
            case '='://括号配对，栈顶括号弹出  
                optr.pop();  
                ch = exp[i++];  
                break;  
            case '>'://栈顶优先权高，先弹出，计算，结果操作数入栈  
                char op = optr.top();  
                optr.pop();  
                int num2 = opnd.top();//第二个操作数在前  
                opnd.pop();  
                int num1 = opnd.top();  
                opnd.pop();  
                  
                int ret = Operate(num1, op, num2);  
                  
                opnd.push(ret);  
                break;  
            }  
        }  
    }//end of while   
  
    //操作数栈的唯一元素即为计算结果  
    return opnd.top();  
}  
 
int main()
{
	char a[1025];
	int res;	
	cin>>a;
	string s=string (a);
	int flag=1;
	for(int i=0;i<s.size();i++)
		if(!(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='('||s[i]==')'||isdigit(s[i])))
		{
			flag=0;
			break;
		}
	if(flag)
	{
		res=CaculateExpression(s);
		cout<<res<<endl;
		cout<<"true"<<endl;
	}
	else
		cout<<"false"<<endl;
	//system("pause");
	 return 0;
	
}