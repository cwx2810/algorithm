//����ƥ��
bool BracketsCheck(char *str){
	//��ʼ��ջ
	InitStack(s);
	i=0;
	//���������鲻����β������
	while(str[i]!='\0'){
		//ɨ��ÿ���ַ�
		switch(str[i]){
			//��������ջ
			case '(':Push(S,'(');break;
			case '[':Push(S,'[');break;
			case '{':Push(S,'{');break;
			//���������ţ����ջ��
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
	//ջ��Ϊ�վ��˳�ѭ������ƥ��
	if(!IsEmpty(S)){
		return false;
	} else{//ջ�գ�ȫ��ƥ�� 
		return true;
	}
}
