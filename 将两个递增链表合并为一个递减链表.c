//�����������ĵ�����ϲ�Ϊһ���ݼ��ĵ����� 
//�����Ƚϣ��ϲ�Ϊ�ݼ�������ͷ�巨���ȽϽ�����������һ������ǿգ������˽���ͷ��������
void MergeList(LinkList& La,LinkList& Lb){
	//��ʼ������ָ�룬�ݴ�ָ��
	LNode *pa=La->next,*pb=Lb->next,*r;
	//�����ⲿ�ռ䣬ֱ�ӰѺϲ���������La�����ڳ�ʼ��֮
	La->next=NULL;
	//����������Ϊ��ʱ������
	while(pa&&pb){
		//���a�е�С��ͷ��a
		if(pa->data<pb->data){
			//r�ݴ�a�ĺ�̣��������
			r=pa->next;
			//ͷ��
			pa->next=La->next;
			La->next=pa;
			//ͨ��r�ָ�pa��Ϊ��һ�αȽ���׼�� 
			pa=r; 
		} else{//���b�е�С��ͷ��b 
			r=pb->next;
			pb->next=La->next;
			La->next=pb;
			pb=r;
		}
		//����ʣ�µķǿ��������aʣ�£�ͳһ�鲢��b����
		if(pa){
			pb=pa;
		} 
		while(pb){
			r=pb->next;
			pb->next=La->next;
			La->next=pb;
			pb=r;
		}
		//�ͷſյ�Lb
		free(Lb); 
	} 
} 
