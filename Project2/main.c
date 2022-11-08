#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) {int t; t=a; a=b; b=t;}

void ViewArr(int*, int );

int count = 0, on=0;
int* origin;

int test = 0;

// ��������
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

// ��������
void BubbleSort(int* base, int n)
{
	int i, j;
	ViewArr(base, n);//���� ���� ��� 
	//������ ������ ����� �����ϴ�.
	for (i = n; i > 1; i--){
		for (j = 1; j < i; j++){
			count++;
			//���� ���Ұ� �� ũ��
			if (base[j - 1] > base[j]){
				SWAP(base[j - 1], base[j]);//��ȯ
				ViewArr(base, n);//���� ���
			}
		}
	}
}

// ��������
void SelectionSort(int* base, int n)
{
	int i, j;
	int maxi;
	ViewArr(base, n);//���� ���� ���
	for (i = n; i > 1; i--)//������ ������ ����� �����ϴ�. 10~2 :9��
	{
		maxi = 0;
		for (j = 1; j < i; j++) // 1~9
		{
			count++;
			if (base[maxi] < base[j])//�� ū ���Ҹ� ������
			{
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);//��ȯ [9][8]
		ViewArr(base, n);//���� ���
	}
}

// ��������
void InsertionSort(int* base, int n)
{
	int i, j;

	ViewArr(base, n);//���� ���� ���
	for (i = 1; i < n; i++)//������ ������ Ȯ���� �����ϴ�.
	{
		// 1~9
		for (j = i; j > 0; j--)
		{
			//1;1>0;j--
			count++;
			if (base[j - 1] > base[j])//���� ���Ұ� �� ũ��
			{
				SWAP(base[j - 1], base[j]);//��ȯ
				ViewArr(base, n);//���� ���
			}
			else
			{
				break;
			}
		}
	}
}

// �������
void PrintSpace(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("   ");
	}
}

// ������
void QuickSort(int* base, int n)
{
	int pivot = 0;           // �ǹ��� ��ġ ����ϴ� ����
	int left = 0, right = 0; // �ǹ����� ū ���� ���� ���� ��ġ�� ã������ ����

	if (n <= 1)
	{
		return;
	}

	left = 0;
	right = n;

	//�� ��Ʈ�� �ǹ����� ���� ������ �������� �̵���Ű�� �ǹ����� ū ������ �������� �̵����Ѽ�
	//���� ����� ū ���� ���̿� �ǹ��� ������ ���� �⺻ �����Դϴ�.
	//�׸��� �� �Ŀ� ���� ������ �ִ� �迭�� ��������� �ٽ� �����ϰ�
	//ū ������ �ִ� �迭�� ��������� �ٽ� �����ϴ� �˰����Դϴ�. 
	while (1)
	{
		//���ʿ� �ǹ�(�ε��� 0�� �ִ� ����)���� ū ���� ���� ������ left�� �̵��մϴ�.
		//for�� �� ���� left�� 1 �����ϸ鼭 ����ϴ� ������ ������ ���� ���� ��ġ���� �����ϱ� ���ؼ��Դϴ�.
		for (left++; (left < n) && (base[0] >= base[left]); left++);

		//���ʿ� �ǹ�(�ε��� 0�� �ִ� ����)���� ���� ���� ���� ������ right�� �̵��մϴ�.
		for (right--; (right > 0) && (base[0] < base[right]); right--);

		//���� left�� right���� �۴ٸ� �ǹ��� ������ �� ���� ���� ū ������ �ڿ� ������ ��ȯ�մϴ�.
		if (left < right)
		{
			SWAP(base[left], base[right]);
			PrintSpace(base - origin);
			ViewArr(base, n);
		}
		//�׷��� �ʴٸ� �ǹ��� �߽����� ���� ����� ū ������ �и� �۾��� ���� ���Դϴ�.
		else
		{
			break;
		}
	}

	//���� �ǹ��� ���� ����� ū ���� ���̷� �����ϴ�.
	SWAP(base[0], base[right]);
	PrintSpace(base - origin);
	ViewArr(base, n);
	printf("left :%d, rigiht :%d\n", left, right);
	//�ǹ����� ���� ������ �ִ� ������ ��� ȣ��� �����մϴ�.
	//QuickSort(base, right);

	//�ǹ����� ū ������ �ִ� ������ ��� ȣ��� �����մϴ�.
	//QuickSort(base + left, n - left);
}

// �迭 ���
void ViewArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}
// �� ����
void quickSort(int base[], int L, int R) {
	int left = L, right = R;
	int pivot = base[(L + R) / 2];    // pivot ���� (���) 
	printf("pivot[%d] : %d L(%d) R(%d)/", (L + R) / 2, pivot, L, R);

	do
	{
		while (base[left] < pivot)    // left�� pivot���� ū ���� �����ų� pivot�� ���� ������ 
			left++;
		while (base[right] > pivot)    // right�� pivot���� ���� ���� �����ų� pivot�� ���� ������ 
			right--;

		//printf("left : %d, right : %d \n", left, right);
		if (left <= right)    // left�� right���� ���ʿ� �ִٸ� ��ȯ 
		{
			SWAP(base[left], base[right]);
			ViewArr(base, 10);
			/*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
			left++;
			right--;
		}
	} while (left <= right);    // left�� right ���� �����ʿ� ���� ������ �ݺ� 
	// �ǹ��� �������� �ǹ����� �������� ������, �ǹ����� ū ���� �������� ������ �۾� ��


	/* recursion */
	if (L < right)
		// ���� �� �ٽ� ����
		quickSort(base, L, right);    // ���� �迭 ��������� �ݺ� 

	if (left < R)
		// �������� �ٽ� ����
		quickSort(base, left, R);    // ������ �迭 ��������� �ݺ� 


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


