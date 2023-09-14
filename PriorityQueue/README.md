# 우선순위 큐
우선순위 큐(priority queue): 우선순위를 가진 항목들을 저장하는 큐  
FIFO순서가 아니라 우선 순위가 높은 데이터가 먼저 나가게 된다.
### 우선순위 큐를 구현하는 방법

- 배열을 이용한 우선순위 큐
- 연결리스트를 이용한 우선순위 큐
- 힙(heep)을 이용한 우선순위 큐

<img width="211" alt="스크린샷 2022-05-10 오전 10 49 14" src="https://user-images.githubusercontent.com/79856225/167526404-05c0c6f6-111b-4a5c-bb66-bf8e02dfeeaf.png">

### 히프(Heap)란?
- 노드의 키들이 다음 식을 만족하는 **완전이진트리**
- Key(부모노드) >= Key(자식노드) 

### 히프의 복잡도 분석

- 삽입 연산에서 최악의 경우, 루트 노드까지 올라가야 하므로 트리의 높이에 해당하는 비교 연산 및 이동 연산이 필요함 O(logn)

- 삭제도 최악의 경우, 가장 아래 레벨까지 내려가야 하므로 역시 트리의 높이 만큼의 시간이 걸린다. -> O(logn)


### 히프(Heap)의 종류
- Max Heap(최대힙)
    - 부모 노드의 키값이 자식 노드의 키값보다 크거나 같은 완전 이진 트리
    - 부모는 무조건 자식보다 크거나 같아야 한다
- Min Heap(최소힙)
    - 부모 노드의 키값이 자식 노드의 키값보다 작거나 같은 완전 이진 트리
    - 부모는 무조건 자식보다 작거나 같아야 한다
#### 이진탐색트리와 다르게 히프(Heap)는 중복된 키값을 허용한다.

### 히프(Heap)의 높이
- N개의 노드를 가지고 있는 히프의 높이는 O(logn)
    -   히프(Heap)는 완전이진트리
    - 마지막 레벨 h을 제외하고는 각 레벨 i에 2^(i-1)개의 노드 존재

### 히프(Heap) 구현방법
- 히프(Heap)는 배열을 이용하여 구현
    - 완전이진트리이므로 각 노드에 번호를 붙일 수 있다.
    - 이 번호를 배열의 인덱스라고 생각
- 부모노드와 자식노드를 찾기가 쉽다.
    - 왼쪽 자식의 인덱스 = 부모의 인덱스 * 2
    - 오른쪽 자식의 인덱스 = 부모의 인덱스 *2+1
    - 부모의 인덱스 = 자식의 인덱스 /2

### 힙(Heap) 정렬

- 힙(Heap))을 이용하면 정렬 가능

- 먼저 정렬해야 할 N개의 요소들을 최대 힙(Heap)에 삽입

- 한번에 하나씩 요소를 힙(Heap)에서 삭제하여 저장하면 된다.

- 삭제되는 요소들은 값이 증가되는 순서(최소힙(Min_Heap)의 경우)

- 하나의 요소를 힙에 삽입하거나 삭제할 때 시간이 O(logn)만큼 소요되고 요소의 개수가 N개이므로 
전체적으로 O(lnogn)시간이 걸린다. (빠른편)

- 힙(Heap) 정렬이 최대로 유용한 경우는 전체 자료를 정렬하는 것이 아니라 가장 큰 값 몇 개만 필요할 때이다.

- 이렇게 힙(Heap)을 사용하는 정렬 알고리즘을 <u>**힙정렬(Heap Sort)**</u>이라고 한다.

### 허프만 코드

- 이진 트리는 각 글자의 빈도가 알려져 있는 메시지의 **내용을 압축**하는데 사용될 수 있다.

- 이런 종류의 이진트리를 허프만 코딩 트리라고 부른다.(빈도수 분석)

1. 알파벳의 빈도수를 나열함 

2. 전체 알파벳의 개수 * 8byte

3. 빈도수가 제일 낮은알파벳부터 묶는다.(2개씩)

4. 다음 빈도수가 낮은 알파벳을 묶을때 그 전에 묶은것도 같이 묶는다.

5. 위 과정을 반복해서 이진트리를 만든다. 

6. 루트 1 왼쪽 0 오른쪽 1 

7. 빈도수가 낮으면 왼쪽 빈도수가 높으면 오른쪽



```c++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct HeapType{ //힙 구조체 선언
    int HEAP[SIZE];
    int heapSize;
}HeapType;

void init(HeapType *H){
    H->heapSize = 0;
} //루트는 1부터 시작이므로 0으로 초기화

void Upheap(HeapType *H){ // 삽입한 노드를 올리면서 최대힙을 만드는 과정
    int i = H->heapSize;  // 현재 인덱스 저장
    int key = H->HEAP[i]; // 현재 값을 저장

    while(i!=1 && key>H->HEAP[i/2]){ //루트가 아니거나 부모노드가 더 작다면 반복 수행
        H->HEAP[i] = H->HEAP[i/2]; // 현재 위치와 부모 위치를 바꾸고
        i = i/2; //i 값 갱신
    }
    H->HEAP[i] = key; //마지막 포인트에 값 삽입
}

void DownHeap(HeapType *H){
    int item = H->HEAP[1]; // 루트값 저장
    
    int parent = 1;
    int child = 2;
    
    while(child <= H->heapSize){ //트리 범위내에서
        if((child < H->heapSize) && (H->HEAP[child+1] > H->HEAP[child])) // 오른쪽 형제가 있다면
            child ++; // 오른쪽으로 이동
        if(item >= H->HEAP[child])
            break; // 이동할 필요가 없다면 멈춤
        H->HEAP[parent] = H->HEAP[child];
        parent = child; // 포인트 이동
        child = child *2;
    }
    H->HEAP[parent] = item; // 해당위치 값 삽입
}

void insertitem(HeapType * H, int key){
    H->heapSize++;
    H->HEAP[H->heapSize]= key;
    // 기본적으로 데이터를 넣어주고 
    Upheap(H);
    // 최대힙을 만들기 위해 제일 아래노드부터 올라가야 함
}

int removeMax(HeapType *H){ //루트 값을 빼고 제일 뒷 노드를 다시 올리는 작업
    int item = H->HEAP[1]; //루트값 저장
    int i = H->heapSize--; // 맨 마지막 값을 올리고 크기 줄이기
    H->HEAP[1] = H->HEAP[i];
    DownHeap(H); // 루트부터 내려가면서 최대힙을 만드는 과정
    return item; // 최대값 반환

}

void HeapSort(HeapType * H){
    int N = H->heapSize;
    int A[N];

    for(int i= N-1; i>=0; i--){
        A[i] = removeMax(H);
    }
    for(int i=0; i<N;i++){
        printf("[%d] ", A[i]);
    }
    printf("\n");
}

void print(HeapType *H){
    for(int i=1; i<=H->heapSize; i++){
        printf("[%d]->", H->HEAP[i]);
    }
    printf("\b\b  \n");
}

int main(){
    srand(time(NULL));

    HeapType H;
    init(&H);

    int testCase = rand()%15;
    for(int i=0; i<testCase; i++){
        insertitem(&H, rand()%100);
    }
    print(&H);
    printf("MAX_VALUE IS -> [%d] \n",removeMax(&H));
    print(&H);
    HeapSort(&H);
    return 0;
}
```


