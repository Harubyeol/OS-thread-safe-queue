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

// 노드 해제
void nfree(Node* node) {
    delete[] node->item.value.data;
    delete node;
}

// 노드 복제
Node* nclone(Node* node) {
    return nalloc(node->item);
}


// 우선순위 삽입 (key 기준 오름차순)
Reply enqueue(Queue* queue, Item item) {
    Reply reply;
    reply.success = true;

    Node* new_node = nalloc(item);
    std::lock_guard<std::mutex> guard(queue->lock);
}

Reply dequeue(Queue* queue) {
	Reply reply = { false, NULL };
	return reply;
}

Queue* range(Queue* queue, Key start, Key end) {
	return NULL;
}
