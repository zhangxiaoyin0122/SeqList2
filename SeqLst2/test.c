#include <stdio.h>
#include <stdlib.h>

typedef struct seqList {
	size_t* _array;
	size_t _size;
	size_t _capacity;
}seqList;
//˳���ĳ�ʼ��
void SeqListInit(seqList* sl) {
	sl->_array = (size_t*)malloc(sizeof(size_t) * 4);
	sl->_size = 0;
	sl->_capacity = 4;
}
//����
void checkCapacity(seqList* sl) {
	if (sl->_size == sl->_capacity) {
		sl->_capacity *= 2;
		sl->_array = (size_t*)realloc(sl->_array, sizeof(size_t)* sl->_capacity);
	}
}

void SeqListPushBlak(seqList* sl, size_t value) {  //β��
	checkCapacity(sl);
	//sl->_array[sl->_size++] = value;
	SeqListInsert(sl, sl->_size, value);
}
//ͷ��
void SeqListPushFront(seqList* sl, size_t value) {
	checkCapacity(sl);
	/*size_t end = sl->_size;
	while (end > 0) {
		sl->_array[end] = sl->_array[end - 1];
	}
	sl->_array[0] = value;
	sl->_size++;*/
	SeqListInsert(sl, 0, value);
}
//βɾ
void SeqListPopBlak(seqList* sl) {
	/*if (sl->_size > 0) {
		sl->_size--;
	}*/
	SeqListErase(sl,sl -> _size-1)
}
//ͷɾ
void SeqListPopFront(seqList* sl) {
	/*size_t start = 1;
	while (sl->_size > 0) {
		sl->_array[start - 1] = sl->_array[start];
		start++;
	}
	sl->_size--;*/
	SeqListErase(sl, 0);
}
//����λ��ǰ����
void SeqListInsert(seqList* sl, size_t pos, size_t value) {
	if (pos <= sl->_size) {
		checkCapacity(sl);
		size_t end = sl->_size;
		while (pos < end) {
			sl->_array[end] = sl->_array[end - 1];
			end--;
		}
		sl->_array[pos] = value;
		sl->_size++;
	}
}
//����λ��ɾ��
void SeqListErase(seqList* sl, size_t pos) {
	if (pos < sl->_size) {
		size_t start = pos + 1;
		while (start < sl->_size) {
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}
//����
int SeqListFind(seqList* sl, size_t value) {
	for (size_t i = 0; i < sl->_size; i++) {
		if (sl->_array[i] == value) {
			return i;
		}
		return -1;
	}
}
//���
void SeqListPrint(seqList* sl) {
	for (size_t i = 0; i < sl->_size; i++) {
		printf("%d ", sl->_array[i]);
	}
}

test() {
	seqList sl;
	SeqListInit(&sl);
	SeqListPushBlak(&sl, 1);
	SeqListPushBlak(&sl, 2);
	SeqListPushBlak(&sl, 3);
	SeqListInsert(&sl, 1, 1);
	SeqListPrint(&sl);
	SeqListFind(&sl, 3);
}
int main() {
	test();
	system("pause");
	return 0;
}
