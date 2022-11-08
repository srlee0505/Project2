#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

void ViewArr(int*, int );

int count = 0, on=0;
int* origin;

int test = 0;

// 순차정렬
void SequenceSort(int* base, int n) {

	int i, j;
	ViewArr(base, n);

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) {
			count++;
			if (base[i] > base[j]) {
				SWAP(base[i], base[j]);
				ViewArr(base, n);
			}
		}
	}
}

// 버블정렬
void BubbleSort(int* base, int n)
{
	int i, j;
	ViewArr(base, n);//현재 상태 출력 
	//정렬할 범위를 축소해 나갑니다.
	for (i = n; i > 1; i--){
		for (j = 1; j < i; j++){
			count++;
			//앞쪽 원소가 더 크면
			if (base[j - 1] > base[j]){
				SWAP(base[j - 1], base[j]);//교환
				ViewArr(base, n);//상태 출력
			}
		}
	}
}

// 선택정렬
void SelectionSort(int* base, int n)
{
	int i, j;
	int maxi;
	ViewArr(base, n);//현재 상태 출력
	for (i = n; i > 1; i--)//정렬할 범위를 축소해 나갑니다. 10~2 :9번
	{
		maxi = 0;
		for (j = 1; j < i; j++) // 1~9
		{
			count++;
			if (base[maxi] < base[j])//더 큰 원소를 만나면
			{
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);//교환 [9][8]
		ViewArr(base, n);//상태 출력
	}
}

// 삽입정렬
void InsertionSort(int* base, int n)
{
	int i, j;

	ViewArr(base, n);//현재 상태 출력
	for (i = 1; i < n; i++)//정렬할 범위를 확대해 나갑니다.
	{
		// 1~9
		for (j = i; j > 0; j--)
		{
			//1;1>0;j--
			count++;
			if (base[j - 1] > base[j])//앞쪽 원소가 더 크면
			{
				SWAP(base[j - 1], base[j]);//교환
				ViewArr(base, n);//상태 출력
			}
			else
			{
				break;
			}
		}
	}
}

// 공란출력
void PrintSpace(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("   ");
	}
}

// 퀵정렬
void QuickSort(int* base, int n)
{
	int pivot = 0;           // 피벗의 위치 기억하는 변수
	int left = 0, right = 0; // 피벗보다 큰 값과 작은 값의 위치를 찾기위한 변수

	if (n <= 1)
	{
		return;
	}

	left = 0;
	right = n;

	//퀵 소트는 피벗보다 작은 값들은 앞쪽으로 이동시키고 피벗보다 큰 값들은 뒤쪽으로 이동시켜서
	//작은 값들과 큰 값들 사이에 피벗을 보내는 것이 기본 동작입니다.
	//그리고 난 후에 작은 값들이 있는 배열을 재귀적으로 다시 정렬하고
	//큰 값들이 있는 배열을 재귀적으로 다시 정렬하는 알고리즘입니다. 
	while (1)
	{
		//앞쪽에 피벗(인덱스 0에 있는 원소)보다 큰 값을 만날 때까지 left를 이동합니다.
		//for문 맨 앞의 left를 1 증가하면서 출발하는 이유는 이전에 끝난 다음 위치부터 시작하기 위해서입니다.
		for (left++; (left < n) && (base[0] >= base[left]); left++);

		//뒤쪽에 피벗(인덱스 0에 있는 원소)보다 작은 값을 만날 때까지 right를 이동합니다.
		for (right--; (right > 0) && (base[0] < base[right]); right--);

		//만약 left가 right보다 작다면 피벗과 비교했을 때 작은 값이 큰 값보다 뒤에 있으니 교환합니다.
		if (left < right)
		{
			SWAP(base[left], base[right]);
			PrintSpace(base - origin);
			ViewArr(base, n);
		}
		//그렇지 않다면 피벗을 중심으로 작은 값들과 큰 값들이 분리 작업이 끝난 것입니다.
		else
		{
			break;
		}
	}

	//이제 피벗을 작은 값들과 큰 값들 사이로 보냅니다.
	SWAP(base[0], base[right]);
	PrintSpace(base - origin);
	ViewArr(base, n);
	printf("left :%d, rigiht :%d\n", left, right);
	//피벗보다 작은 값들이 있는 앞쪽을 재귀 호출로 정렬합니다.
	//QuickSort(base, right);

	//피벗보다 큰 값들이 있는 뒤쪽을 재귀 호출로 정렬합니다.
	//QuickSort(base + left, n - left);
}

// 배열 출력
void ViewArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}
// 퀵 정렬
void quickSort(int base[], int L, int R) {
	int left = L, right = R;
	int pivot = base[(L + R) / 2];    // pivot 설정 (가운데) 
	printf("pivot[%d] : %d L(%d) R(%d)/", (L + R) / 2, pivot, L, R);

	do
	{
		while (base[left] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
			left++;
		while (base[right] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
			right--;

		//printf("left : %d, right : %d \n", left, right);
		if (left <= right)    // left가 right보다 왼쪽에 있다면 교환 
		{
			SWAP(base[left], base[right]);
			ViewArr(base, 10);
			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 
	// 피벗을 기준으로 피벗보다 작은수는 오른쪽, 피벗보다 큰 수는 왼쪽으로 나누는 작업 끝


	/* recursion */
	if (L < right)
		// 왼쪽 을 다시 정렬
		quickSort(base, L, right);    // 왼쪽 배열 재귀적으로 반복 

	if (left < R)
		// 오른쪽을 다시 정렬
		quickSort(base, left, R);    // 오른쪽 배열 재귀적으로 반복 


}

int static compare_asc(const void* first, const void* second)
{

	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int static compare_desc(const void* first, const void* second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else if (*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}

void main(void) {
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };

	int array_size = sizeof(arr) / sizeof(int);
	ViewArr(arr, 10);

	qsort(arr, array_size, sizeof(int), compare_asc);
	ViewArr(arr, 10);
}


