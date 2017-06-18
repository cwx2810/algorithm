//括号匹配
bool BracketsCheck(char *str){
	//初始化栈
	InitStack(s);
	i=0;
	//当给定数组不到结尾，迭代
	while(str[i]!='\0'){
		//扫描每个字符
		switch(str[i]){
			//左括号入栈
			case '(':Push(S,'(');break;
			case '[':Push(S,'[');break;
			case '{':Push(S,'{');break;
			//遇到右括号，检测栈顶
			case ')':Pop(S,e);
				if(e!='(') return false;
			break; 
			case ']':Pop(S,e);
				if(e!='[') return false;
			break;
			case '}':Pop(S,e);
				if(e!='{') return false;
			break;
			default:break;
		}
		i++; 
	} 
	//栈不为空就退出循环，不匹配
	if(!IsEmpty(S)){
		return false;
	} else{//栈空，全都匹配 
		return true;
	}
}
