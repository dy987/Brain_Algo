#include "LinkedQueue.h"

void  LQ_CreateQueue( LinkedQueue** Queue )
{
    /*  큐를 자유저장소에 생성 */

}

void LQ_DestroyQueue( LinkedQueue* Queue )
{
  
    /*  큐를 자유 저장소에서 해제 */
    free( Queue );
}

Node* LQ_CreateNode( char* NewData )
{
   

  

    return NewNode;/*  노드의 주소를 반환한다. */
}

void  LQ_DestroyNode(Node* _Node )
{
    
}

void LQ_Enqueue( LinkedQueue* Queue, Node* NewNode )
{
   
}

Node* LQ_Dequeue( LinkedQueue* Queue )
{
    /*  LQ_Dequeue() 함수가 반환할 최상위 노드 */
  
   

    return Front;
}

int LQ_IsEmpty( LinkedQueue* Queue )
{
    return ( Queue->Front == NULL);
}