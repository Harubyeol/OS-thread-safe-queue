#ifndef _QTYPE_H  // header guard
#define _QTYPE_H

#include <atomic>
#include <mutex>

typedef unsigned int Key;

typedef struct {
    char* data;  // 실제 데이터에 대한 포인터 (1B~1KB)
    unsigned int length;  // 데이터 길이 (최대 1024)
} Value;
// ==========이 파일은 수정 가능==========

typedef unsigned int Key;  // 값이 클수록 높은 우선순위
typedef void* Value;

typedef struct {
    Key key;
    Value value;
} Item;

typedef struct {
    bool success;   // true: 성공, false: 실패
    Item item;
    // 필드 추가 가능
} Reply;

typedef struct node_t {
    Item item;
    struct node_t* next;
    // 필드 추가 가능
} Node;

typedef struct {
    Node* head
    Node* tail;
    // 필드 추가 가능
    std::mutex lock; // 큐 전체에 대한 락
} Queue;

// 이후 자유롭게 추가/수정: 새로운 자료형 정의 등

#endif
