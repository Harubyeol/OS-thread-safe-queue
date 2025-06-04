#include <iostream>
#include "queue.h"
#include <cstring>

// 큐 초기화
Queue* init(void) {
    Queue* queue = new Queue;
    queue->head = nullptr;
    queue->tail = nullptr;
    return queue;
}


// 큐 해제
void release(Queue* queue) {
    Node* curr = queue->head;
    while (curr) {
        Node* next = curr->next;
        nfree(curr);
        curr = next;
    }
    delete queue;
}

// 노드 생성
Node* nalloc(Item item) {
    Node* node = new Node;
    node->item.key = item.key;
    node->item.value.length = item.value.length;

    node->item.value.data = new char[item.value.length];
    std::memcpy(node->item.value.data, item.value.data, item.value.length);

    node->next = nullptr;
    return node;
}


void nfree(Node* node) {
	return;
}


Node* nclone(Node* node) {
	return NULL;
}


Reply enqueue(Queue* queue, Item item) {
	Reply reply = { false, NULL };
	return reply;
}

Reply dequeue(Queue* queue) {
	Reply reply = { false, NULL };
	return reply;
}

Queue* range(Queue* queue, Key start, Key end) {
	return NULL;
}
