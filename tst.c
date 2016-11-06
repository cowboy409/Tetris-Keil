	// Tetris 생성부
if (Tmove2==100 || Tmove2==100)
{
	delay2=TIM4->CNT;
	blk22=delay2- (delay2/7)*7+1;
	e=1;
	f=1;
	
	if(Tmove2==100)
	{
			for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
			{
					Tblk2[for_t1][for_t2]=0;
			}
		}
	if (blk2==1){
		Tblk2[e][f]=1;
		Tblk2[e][f-1]=1;
		Tblk2[e-1][f-1]=1;
		Tblk2[e+1][f]=1;

}
	else if (blk2==2){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e-1][f]=1;
		Tblk2[e+1][f-1]=1;
		
	
	}		
		else if (blk2==3){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e+1][f]=1;
		Tblk2[e-1][f]=1;

	}		
			else if (blk2==4){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e+1][f]=1;
		Tblk2[e+1][f-1]=1;

			}
			else if (blk2==5){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e][f+1]=1;
			}
				
					else if (blk2==6){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e][f+1]=1;
		Tblk2[e-1][f-1]=1;
			
	}		
						else if (blk2==7){
		Tblk2[e][f] =1;
		Tblk2[e][f-1]=1;
		Tblk2[e][f+1]=1;
		Tblk2[e+1][f-1]=1;
								
	}
						
	Trot2=0;
	Tmove2=101;
	Ttype2=blk2;
	Tx2=12;
	Txt2=12;
	Ty2=14;
	Tyt2=14;

}
}


// 구동부
if(Tmove2!=100)
{
	Tmove2=key;
	
	//Auto Down 구문
	if (key !=13 && key!=5 && key!=1)
	{
			if (autodown2 >10 )
	{	Tmove2=9;
			key=9;
			autodown2=0;}
	}
	
	if(Tmove2==13) { // 왼쪽
		Tx2++;
	}
	else if(Tmove2==9) { //아래
		Ty2--; }
	else if(Tmove2==12) { //오른쪽
		Tx2--;	}
	else if(Tmove2==1)	{ //회전
		Trot2=1;
		p=1;
		q=1;
		
	
		
	}
	Tmove2=0;
	
}






// Tetris 연산부

//if(Ttype2!=5)
{
	if(key==1 || key==5 || key==9 || key==13 || Tmove2==101 )
	{
			// 3x3 도장 찍은거 지우기
		{
			if (Tdel2==77 )
	{		for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
				{
					if(TData[Txt2-1+for_t1][Tyt2-1+for_t2]>0)
					{TData[Txt2-1+for_t1][Tyt2-1+for_t2] -= Tblk2[for_t1][for_t2];
					}
				}
				}
	}
}

	

if ( Trot2==1)
{
			temp1=Tblk2[p+1][q-1];//save3 
		 temp2=Tblk2[p+1][q];//save4

		 Tblk2[p+1][q-1]=Tblk2[p-1][q-1];//3<-1
		 Tblk2[p+1][q]=Tblk2[p][q-1];//4<-2
				
		 Tblk2[p][q-1]=Tblk2[p-1][q];//2<-8;
		 Tblk2[p-1][q-1]=Tblk2[p-1][q+1];//1<-7
				
		 Tblk2[p-1][q]=Tblk2[p][q+1];//8<-6;
		 Tblk2[p-1][q+1]=Tblk2[p+1][q+1];//7<-5;
				
		 Tblk2[p+1][q+1]=temp1; //5<-3(temp1)
		 Tblk2[p][q+1]=temp2; //6<-4 (temp2)       
			//회전 state 입력	
			
}

//	 이동해도 되는지 확인
		for(for_t1=0;for_t1<3;for_t1++)
	{
		for(for_t2=0;for_t2<3;for_t2++)
		{
			TData[Tx2-1+for_t1][Ty2-1+for_t2] += Tblk2[for_t1][for_t2];
			if (TData[Tx2-1+for_t1][Ty2-1+for_t2] ==2)
			{
				Talert2=999;
			}
		}
		
	}

	
	// 좌표 중첩 (2되는거) alert 가 뜨면 
	if(Talert2==999)
	{
				for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
				{
					TData[Tx2-1+for_t1][Ty2-1+for_t2] -= Tblk2[for_t1][for_t2];
					}
				}
		// 화면 복구는 했고
				// 이제 이전 state 로 돌아갖
				
			if ( Trot2==1)
			{
					temp1=Tblk2[p+1][q-1];//save3 
				 temp2=Tblk2[p+1][q];//save4
				 
				 Tblk2[p+1][q-1]=Tblk2[p+1][q+1];//3<-5
				 Tblk2[p+1][q]=Tblk2[p][q+1];//4<-6
						
				Tblk2[p+1][q+1]=Tblk2[p-1][q+1];//5<-7
				 Tblk2[p][q+1]=Tblk2[p-1][q];//6<-8
				 
				 Tblk2[p-1][q+1]=Tblk2[p-1][q-1];//7<-1
				 Tblk2[p-1][q]=Tblk2[p][q-1];//8<-2
				 
				 Tblk2[p-1][q-1]=temp1;//1<-3(temp1)
				 Tblk2[p][q-1]=temp2;//2<-4(temp2)
					Trot2=0;
			}
			else // j이동을 복구
			{
					Tx2= Txt2;
					Ty2= Tyt2;
					
			}
			
			// 다시 새로운 화면을 뿌려짐
			for(for_t1=0;for_t1<3;for_t1++)
					{
						for(for_t2=0;for_t2<3;for_t2++)
						{
							TData[Tx2-1+for_t1][Ty2-1+for_t2] += Tblk2[for_t1][for_t2];
							
						}
					}
					
					Talert2=0;
					Tdel2=77;
					
			if(key==8)
			{
					Tmove2=100;
			}
			
		}
	else
	{
			Txt2=Tx2;
			Tyt2=Ty2;
			Tdel2=77;
	}
			


	
	
	//
	Trot2=0;
	
	}
	/// 사실상 연산종료
	
}
		