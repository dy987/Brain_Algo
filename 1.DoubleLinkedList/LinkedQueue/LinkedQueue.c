#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    /*  ť�� ��������ҿ� ���� */

}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
  
    /*  ť�� ���� ����ҿ��� ���� */
    free( Queue );
}

Node* LQ_CreateNode( char* NewData )
{
   

  

    return NewNode;/*  ����� �ּҸ� ��ȯ�Ѵ�. */
}

void  LQ_DestroyNode(Node* _Node )
{
    
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
   
}

Node* LQ_Dequeue( LinkedQueue* Queue )
{
    /*  LQ_Dequeue() �Լ��� ��ȯ�� �ֻ��� ��� */
  
   

    return Front;
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL);
}