#include <stm32f10x.h>     


u16 sdata, cdata, cdata_temp;
int TData [19][18], makenew,autodown,dectemp;

int Tblk1[3][3], Tblk11[4][4], Tx1, Txt1, Ty1, Tyt1, Tmove1, Ttype1, Trot1,Talert1,Tdel1, Tline1, Tline2;

int Tblk2[3][3], Tblk22[3][4], Tx2, Txt2, Ty2, Tyt2, Tmove2, Ttype2, Trot2, Talert2, Tdel2, p1end, p2end,p1c, p1r, p2c, p2r;

int p1e1, p2e1;
int autodown1, autodown2;
int Tline_tmp1, Tline_tmp2, Tline1,Tline2,Tline_attack1,Tline_attack2;



u16 scanpat[4] = { 0xFFFE,0xFFFD,0xFBFF, 0xF7FF};
u16 colpat[4] = {0x0001, 0x0002, 0x0004, 0x0008};
u8 key;
//글로벌변수
int ii,jj,blk,blk2,e,f,p,q,delay,delay2,keydelay, temp1, temp2, temp3, temp4;
	u8 c;

int main (void) {
	
{		
	int i,j;
	//GPIO & AFIO Setup
	
  RCC->APB2ENR = 0x000000FD;
	GPIOA->CRL = 0x33333333;
	GPIOA->CRH = 0x33333333;
	GPIOB->CRL = 0x33333333;
	GPIOB->CRH = 0x88883333;
	GPIOB->ODR |= 0xFC03; //input with pull-up (PB15-12)
	GPIOC->CRL = 0x33333333;
	GPIOC->CRH = 0x33333333;
	GPIOD->CRL = 0x33333333;
	
  AFIO->MAPR |= 0x000010C0;
	
	//Tim1, Tim4 Setup
	 RCC->APB1ENR |= 0x00000004;
	RCC->APB2ENR |= 0x00000800;
	TIM1->CR1 =0x00;
	TIM1->CR2 = 0x00;
	TIM1->PSC = 0x009F;
	TIM1->ARR = 0x116F;
	TIM4->CR1 =0x00;
	TIM4->CR2 = 0x00;
	TIM4->PSC = 0x009F;
	TIM4->ARR = 0x124D;
	
	TIM4->DIER |= 0x0001;
	TIM1->DIER |= 0x0001;
	NVIC->ISER[0] |= (1<<30);
	NVIC->ISER[0] |= (1<<25);
	
	TIM1->CR1 |= 0x0001;
	TIM4->CR1 |= 0x0001;
	
	GPIOA->ODR=0x0000;
	GPIOB->ODR=0xFE1F;
	GPIOC->ODR=0xFFFF;
	
		// Display  Matrix 
//for(i=0;i<16;i++)
	//{for(j=0;j<16;j++)
		//{
			//	if(i>j)
				//{TData[i][j]=1;
		//}
	//}
	//}
	
	//초기 셋팅
	Tmove1=100;
	Tmove2=100;
	p1c=0;
	p2c=0;
	Tline1=0;
	Tline2=0;
	p1e1=0;
	p2e1=0;
	Tline_attack2 =0;
	Tline_tmp1 = 0;
	Tline_attack1 =0;
	Tline_tmp2 = 0;
	// 가장자리 셋팅
	for(i=0;i<17;i++)
	{
		for(j=0;j<19;j++)
		{
			TData[j][i]=0;
	}
}
	for(i=0;i<18;i++)
	{
		TData[i][0]=1;
		TData[0][i]=1;
		TData[9][i]=1;
		TData[18][i]=1;
		TData[i][17]=1;
	}
}
	
while (1) {

	int i;
	int j;
	int a;
	int b;
	int k=0xFFFFFFFF;
	int r=600;
	int g=2200;




// 초록색을 빨강색의 3배 시간 켜기

// 이하 초록색부터 켜기
{
//------------PC8~ PC13 불켜기----------------------------
		for(j=8;j<14;j++)			{ 
					a=0x00000000;
					k=0xFFFFFFFF;
					k &= 0xFFFEFFFF>>(16-j);
					GPIOA->ODR = a;
			
					GPIOB->ODR &=0xFE1F;
					GPIOC->ODR = k;
				//----------  PA1~PA12 , PB5~8  ------ 세트시작

					for(i=0;i<12;i++)				{
							if(TData[j+2][i+1]==1)		{a += 1<<(i+1);}
								}
					GPIOA->ODR = a;
					
					a=0x00000000;
								
					for(i=12;i<16;i++)
					{
							if(TData[j+2 ][i+1]==1)		{a += 1<<(i-7);}
								}
					GPIOB->ODR |= a;
				//----------  PA1~PA12 , PB5~8  ------ 세트끝

								
					for(b=0;b<g;b++);
						}
					
					GPIOC->ODR =0xFFFF;
					GPIOB->ODR &=0xFE1F;
					a=0x00000000;
						
//-----------------PB2 라인 불켜기---------------------------						
					
						GPIOB->ODR &= 0XFFFB;
						//----------  PA1~PA12 , PB5~8  ------ 세트시작
					for(i=0;i<12;i++)				{	
								if(TData[j+2 ][i+1]==1)		{a += 1<<(i+1);}}
					GPIOA->ODR = a;
					
					a=0x00000000;
					for(i=12;i<16;i++)
					{
							if(TData[j +2][i+1]==1)		{a += 1<<(i-7);}
								}
					GPIOB->ODR |= a;
					//----------  PA1~PA12 , PB5~8  ------ 세트끝
				
					j++;
					for(b=0;b<g;b++);
					GPIOB->ODR |= 0X0004;
					GPIOB->ODR &=0xFE1F;
					a=0x00000000;
								
	//-----------------PB9 라인 불켜기---------------------------						
					GPIOB->ODR &= 0xFDFF;
					//----------  PA1~PA12 , PB5~8  ------ 세트시작
					for(i=0;i<12;i++)				{	
								if(TData[j +2][i+1]==1)		{a += 1<<(i+1);}}
					GPIOA->ODR = a;
								
					a=0x00000000;
					for(i=12;i<16;i++)
					{
							if(TData[j+2 ][i+1]==1)		{a += 1<<(i-7);}
								}
					GPIOB->ODR |= a;
								
					//----------  PA1~PA12 , PB5~8  ------ 세트끝
								
					j++;
					for(b=0;b<g;b++);
					GPIOB->ODR |= 0x0200;
					GPIOB->ODR &=0xFE1F;
					a=0x00000000;				
		


				
							}
				

// 이하 빨간색 켜기
{
//------------PC0~ PC7 불켜기----------------------------
		for(j=0;j<8;j++)			{ 
					a=0x00000000;
					k=0xFFFFFFFF;
					k &= 0xFFFEFFFF>>(16-j);
					GPIOA->ODR = a;
			
					GPIOB->ODR &=0xFE1F;
					GPIOC->ODR = k;
				//----------  PA1~PA12 , PB5~8  ------ 세트시작

					for(i=0;i<12;i++)				{
							if(TData[j+1 ][i+1]==1)		{a += 1<<(i+1);}
								}
					GPIOA->ODR = a;
					
					a=0x00000000;
								
					for(i=12;i<16;i++)
					{
							if(TData[j +1][i+1]==1)		{a += 1<<(i-7);}
								}
					GPIOB->ODR |= a;
				//----------  PA1~PA12 , PB5~8  ------ 세트끝

								
					for(b=0;b<r;b++);
						}
					
					GPIOC->ODR =0xFFFF;
					a=0x00000000;

								
							}
				
		

								





//while 의 끝

}




}

void TIM4_IRQHandler (void){

	
	GPIOB->ODR |= 0xFC03;
	cdata_temp = 0x0000;
	c=0;
	
	// KEY 값 받기
while(c<4){


	GPIOB->ODR &=  scanpat[c];
	
	for(keydelay=0;keydelay<10;keydelay++);
	
	cdata_temp = (~GPIOB->IDR)>>12;
	cdata =0x000F & cdata_temp;
		
		
	if(c==0){
		if(cdata == 0x0001){
				key=1;
			
				c=100;}
	
		else if (cdata == 0x0002) {
				key=2;
				c=100;		}
		else if (cdata == 0x0004){
							key=3;
							c=100;
		}
		else if (cdata == 0x0008){
							key=4;
							c=100;
		}
	}

	else if(c==1){
		if(cdata == 0x0001){
										key=5;
							c=100;
		}
		else if (cdata == 0x0002) {
										key=6;
							c=100;
		}
		else if (cdata == 0x0004){
										key=7;
							c=100;
		}
		else if (cdata == 0x0008){
										key=8;
							c=100;
		}
}
	else if(c==2){
		if(cdata == 0x0001){
											key=9;
							c=100;
		}
		else if (cdata == 0x0002) {
											key=10;
							c=100;
		}
		else if (cdata == 0x0004){
										key=11;
							c=100;
		}
		else if (cdata == 0x0008){
											key=12;
							c=100;
		}
}
	else if(c==3){
		if(cdata == 0x0001){
											key=13;
							c=100;
		}
		else if (cdata == 0x0002) {
										key=14;
							c=100;
		}
		else if (cdata == 0x0004){
											key=15;
							c=100;	}
		else if (cdata == 0x0008){
											key=16;
							c=100;
		}
}

	
	
	
	
	

c++;
}



	


TIM4->SR &= ~0x1;

}


void TIM1_UP_TIM16_IRQHandler (void)

{
	int for_t1,for_t2,for_t3,for_t4;
	int i, j, k;
	
	
if(p1end!=1){	
	// Tetris 생성부
if (Tmove1==100 )
{
	delay=TIM4->CNT;
	blk=delay- (delay/7)*7+1;
	e=1;
	f=1;
	
	if(Tmove1==100)
	{
			for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
			{
					Tblk1[for_t1][for_t2]=0;
			}
		}
	if (blk==1){
		Tblk1[e][f]=1;
		Tblk1[e][f-1]=1;
		Tblk1[e-1][f-1]=1;
		Tblk1[e+1][f]=1;

}
	else if (blk==2){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e-1][f]=1;
		Tblk1[e+1][f-1]=1;
		
	
	}		
		else if (blk==3){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e+1][f]=1;
		Tblk1[e-1][f]=1;

	}		
			else if (blk==4){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e+1][f]=1;
		Tblk1[e+1][f-1]=1;

			}
			else if (blk==5){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e][f+1]=1;
			}
				
					else if (blk==6){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e][f+1]=1;
		Tblk1[e-1][f-1]=1;
			
	}		
						else if (blk==7){
		Tblk1[e][f] =1;
		Tblk1[e][f-1]=1;
		Tblk1[e][f+1]=1;
		Tblk1[e+1][f-1]=1;
								
	}
						
	Trot1=0;
	Tmove1=101;
	Ttype1=blk;
	Tx1=5;
	Txt1=5;
	Ty1=1;
	Tyt1=1;

}
}


// 구동부
if(Tmove1!=100)
{
	Tmove1=key;
	
	//Auto Down 구문
	if (key !=4 && key!=12 && key!=16)
	{
			if (autodown1 >10 )
	{	Tmove1=8;
			key=8;
			autodown1=0;}
	}
	
	if(Tmove1==4) { // 왼쪽
		Tx1--;
	}
	else if(Tmove1==8) { //아래
		Ty1++; }
	else if(Tmove1==12) { //오른쪽
		Tx1++;	}
	else if(Tmove1==16)	{ //회전
		Trot1=1;
		p=1;
		q=1;
		
	
		
	}
	Tmove1=0;
	
}






// Tetris 연산부

//if(Ttype1!=5)
{
	if(key==4 || key==8 || key==12 || key==16 || Tmove1==101 )
	{
			// 3x3 도장 찍은거 지우기
		{
			if (Tdel1==77 )
	{		for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
				{
					if(TData[Txt1-1+for_t1][Tyt1-1+for_t2]>0)
					{TData[Txt1-1+for_t1][Tyt1-1+for_t2] -= Tblk1[for_t1][for_t2];
					}
				}
				}
	}
}

	

if ( Trot1==1)
{
			temp1=Tblk1[p+1][q-1];//save3 
		 temp2=Tblk1[p+1][q];//save4

		 Tblk1[p+1][q-1]=Tblk1[p-1][q-1];//3<-1
		 Tblk1[p+1][q]=Tblk1[p][q-1];//4<-2
				
		 Tblk1[p][q-1]=Tblk1[p-1][q];//2<-8;
		 Tblk1[p-1][q-1]=Tblk1[p-1][q+1];//1<-7
				
		 Tblk1[p-1][q]=Tblk1[p][q+1];//8<-6;
		 Tblk1[p-1][q+1]=Tblk1[p+1][q+1];//7<-5;
				
		 Tblk1[p+1][q+1]=temp1; //5<-3(temp1)
		 Tblk1[p][q+1]=temp2; //6<-4 (temp2)       
			//회전 state 입력	
			
}

//	 이동해도 되는지 확인
		for(for_t1=0;for_t1<3;for_t1++)
	{
		for(for_t2=0;for_t2<3;for_t2++)
		{
			TData[Tx1-1+for_t1][Ty1-1+for_t2] += Tblk1[for_t1][for_t2];
			if (TData[Tx1-1+for_t1][Ty1-1+for_t2] ==2)
			{
				Talert1=999;
			}
		}
		
	}

	
	// 좌표 중첩 (2되는거) alert 가 뜨면 
	if(Talert1==999)
	{
						for(for_t1=0;for_t1<3;for_t1++)
		{
			for(for_t2=1;for_t2<3;for_t2++)
			{
				if(TData[4+for_t1][for_t2]==2){
					p1end=1;
				}
			}
		}
				for(for_t1=0;for_t1<3;for_t1++)
		{
				for(for_t2=0;for_t2<3;for_t2++)
				{
					TData[Tx1-1+for_t1][Ty1-1+for_t2] -= Tblk1[for_t1][for_t2];
					}
				}
		// 화면 복구는 했고
				// 이제 이전 state 로 돌아갖
				
			if ( Trot1==1)
			{
					temp1=Tblk1[p+1][q-1];//save3 
				 temp2=Tblk1[p+1][q];//save4
				 
				 Tblk1[p+1][q-1]=Tblk1[p+1][q+1];//3<-5
				 Tblk1[p+1][q]=Tblk1[p][q+1];//4<-6
						
				Tblk1[p+1][q+1]=Tblk1[p-1][q+1];//5<-7
				 Tblk1[p][q+1]=Tblk1[p-1][q];//6<-8
				 
				 Tblk1[p-1][q+1]=Tblk1[p-1][q-1];//7<-1
				 Tblk1[p-1][q]=Tblk1[p][q-1];//8<-2
				 
				 Tblk1[p-1][q-1]=temp1;//1<-3(temp1)
				 Tblk1[p][q-1]=temp2;//2<-4(temp2)
					Trot1=0;
			}
			else // j이동을 복구
			{
					Tx1= Txt1;
					Ty1= Tyt1;
					
			}
			
			// 다시 새로운 화면을 뿌려짐
			for(for_t1=0;for_t1<3;for_t1++)
					{
						for(for_t2=0;for_t2<3;for_t2++)
						{
							TData[Tx1-1+for_t1][Ty1-1+for_t2] += Tblk1[for_t1][for_t2];
							
						}
					}
					
					Talert1=0;
					Tdel1=77;
					
			if(key==8)
			{
					Tmove1=100;
			}
			
		}
	else
	{
			Txt1=Tx1;
			Tyt1=Ty1;
			Tdel1=77;
	}
			


	
	
	//
	Trot1=0;
	
	}
	/// 사실상 연산종료
	
}
}

// 1P 줄수 clear 감지
if(p1end!=1){
if(key==8 && Tmove1==100)
{
for (j=16;j>0;j--)	// 어떤 한 줄에 대하여
{
	{
	for(i=1;i<9;i++)		// x값을 다 확인해본다. 
	{
		Tline_tmp1 += TData[i][j];
	}
	
	if( Tline_tmp1 ==8)  // 합한결과 8이면 라인 clear
	{
			for(i=1;i<9;i++)		// 해당 라인 0 으로 초기화해주고
		{
				TData[i][j]=0;
		}
		
		// 해당 라인 윗부분 다 땡겨온다.
		for(k=j;k>1;k--) 
		{
			for(i=1;i<9;i++)
			{
					TData[i][k] = TData[i][k -1];
			}
		}
		
		Tline1 ++;
		Tline_attack2 ++;
		j++;
	}
	Tline_tmp1 = 0;
}

		// 라인 clear if문 닫기
	}

}
}

// 2P 가 1P 에게 공격
if(p1end!=1){
if(Tline_attack1>0)
{
	for(j=1;j<16;j++)
	{
			for(i=1;i<9;i++)		
		{
			TData[i][j]=TData[i][j+1];
		}
	}
		for(i=1;i<9;i++)
	{
			TData[i][j]=1;
	}
		TData[1+blk2][j]=0;
	Tline_attack1 --;
	Ty1--;
	Tyt1--;
}
}




if(p2end!=1){
	// Tetris 생성부 2P
if (Tmove2==100 )
{
	delay2=TIM4->CNT;
	blk2=delay2- (delay2 /7)*7+1;
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
	Tx2=14;
	Txt2=14;
	Ty2=17;
	Tyt2=17;

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
	else if(Tmove2==5) { //오른쪽
		Tx2--;	}
	else if(Tmove2==1)	{ //회전
		Trot2=1;
		p=1;
		q=1;
		
	
		
	}
	Tmove2=0;
	
}






// Tetris 연산부

//if(Ttype1!=5)
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
			temp3=Tblk2[p+1][q-1];//save3 
		 temp4=Tblk2[p+1][q];//save4

		 Tblk2[p+1][q-1]=Tblk2[p-1][q-1];//3<-1
		 Tblk2[p+1][q]=Tblk2[p][q-1];//4<-2
				
		 Tblk2[p][q-1]=Tblk2[p-1][q];//2<-8;
		 Tblk2[p-1][q-1]=Tblk2[p-1][q+1];//1<-7
				
		 Tblk2[p-1][q]=Tblk2[p][q+1];//8<-6;
		 Tblk2[p-1][q+1]=Tblk2[p+1][q+1];//7<-5;
				
		 Tblk2[p+1][q+1]=temp3; //5<-3(temp1)
		 Tblk2[p][q+1]=temp4; //6<-4 (temp2)       
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
			for(for_t2=0;for_t2<2;for_t2++)
			{
				if(TData[13+for_t1][15+for_t2]==2){
					p2end=1;
				}
			}
		}

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
					temp3=Tblk2[p+1][q-1];//save3 
				 temp4=Tblk2[p+1][q];//save4
				 
				 Tblk2[p+1][q-1]=Tblk2[p+1][q+1];//3<-5
				 Tblk2[p+1][q]=Tblk2[p][q+1];//4<-6
						
				Tblk2[p+1][q+1]=Tblk2[p-1][q+1];//5<-7
				 Tblk2[p][q+1]=Tblk2[p-1][q];//6<-8
				 
				 Tblk2[p-1][q+1]=Tblk2[p-1][q-1];//7<-1
				 Tblk2[p-1][q]=Tblk2[p][q-1];//8<-2
				 
				 Tblk2[p-1][q-1]=temp3;//1<-3(temp1)
				 Tblk2[p][q-1]=temp4;//2<-4(temp2)
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
					
			if(key==9)
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
}

// 2P 줄수 clear 감지
if(p2end!=1){
if(key==9 && Tmove2==100)
{
for (j=1;j<15;j++)	// 어떤 한 줄에 대하여
{
	{
	for(i=10;i<18;i++)		// x값을 다 확인해본다. 
	{
		Tline_tmp2 += TData[i][j];
	}
	
	if( Tline_tmp2 ==8)  // 합한결과 8이면 라인 clear
	{
			for(i=10;i<18;i++)		// 해당 라인 0 으로 초기화해주고
		{
				TData[i][j]=0;
		}
		
		// 해당 라인 윗부분 다 땡겨온다.
		for(k=j;k<15;k++) 
		{
			for(i=10;i<18;i++)
			{
					TData[i][k] = TData[i][k+1];
			}
		}
		
		Tline2 ++;
		Tline_attack1 ++;
	}
	
	Tline_tmp2 = 0;
}

		// 라인 clear if문 닫기
	}

}
}

// 1P 가 2P 에게 공격
if(p2end!=1){
if  (Tline_attack2>0)
{
	for(j=16;j>1;j--)
	{
			for(i=10;i<18;i++)		
		{
			TData[i][j]=TData[i][j-1];
		}
	}
		for(i=10;i<18;i++)
	{
			TData[i][j]=1;
	}
		TData[11+blk2][j]=0;
	Tline_attack2 --;
	Ty2++;
	Tyt2++;
	
}
}
//1p죽음
if(p1end==1){
	if(p1e1==0){
	if(p1c<16){
		for(for_t3=1;for_t3<9;for_t3++){
			TData[for_t3][16-p1c]=1;
		}
		p1c++;
	}
	else if(p1c==16){p1c=0;
	p1e1++;}
}
	else if (p1e1==1){
	for(for_t1=1;for_t1<9;for_t1++){
		for(for_t2=1;for_t2<17;for_t2++){
		TData[for_t1][for_t2]=0;
		}
	}
p1e1++;
}
else if (p1e1==2){
if(p1c<Tline1){
for(for_t3=1;for_t3<9;for_t3++){
TData[for_t3][16-p1c]=1;
}
p1c++;
}
}
}
//2p죽음
if(p2end==1){
	if(p2e1==0){
	if(p2c<16){
		for(for_t4=10;for_t4<18;for_t4++){
			TData[for_t4][p2c+1]=1;
		}
		p2c++;
	}
	else if(p2c==16){p2c=0;
	p2e1++;}
}
else if (p2e1==1){
	for(for_t1=10;for_t1<18;for_t1++){
		for(for_t2=1;for_t2<17;for_t2++){
		TData[for_t1][for_t2]=0;
		}
	}
	p2e1++;
}
else if(p2e1==2){
	if(p2c<Tline2){
		for(for_t3=10;for_t3<18;for_t3++){
		TData[for_t3][p2c+1]=1;
		}
		p2c++;
	}
}
}

key=0;
autodown2++;
autodown1++;
// ISR  종료
TIM1->SR &= ~0x1;

	
}
