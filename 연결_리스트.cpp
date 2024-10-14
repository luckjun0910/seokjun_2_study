#include "..\CookHeader.h"

// 구조체 선언
typedef struct _Node {
    string name;
    string phone;
    struct _Node* link = NULL;
} Node;

Array<Node*> memory;
Node* head = NULL;

void addNode(string name,string phone) {
    // 전화번호 중복 체크
    for (Node* current = head; current != NULL; current = current->link) { //링크가 없어질때 까지 반복
        if (current->phone == phone) { //원래 있던 폰과 위에 입력으로 들어온 폰이 똑같은지 확인
            println("전화번호가 중복입니다. 추가할 수 없습니다.");
            return;
        }
    }

    //구조체 첫 데이터 ? 넣기
    Node* node = new Node;
    node->name = name;
    node->phone = phone;
    node->link = head;
    head = node;
    memory.push_back(node);
    println("노드가 추가되었습니다.");
}

void deleteNode() {
    if (head == NULL) { // 노드가 없으면 끝
        println("삭제할 데이터가 없습니다.");
        return;
    }

    println("삭제할 데이터 목록:");
    Node* current = head;
    int a = 1; // 데이터 목록을 숫자로 보여주기 위함

    while (current != NULL) {
        println(a << ": " << current->name);
        current = current->link; // 보여주고 다음 데이터로
        a++; // 숫자 올리기
    }

    int sunteck;
    input(sunteck, "삭제할 노드의 번호를 입력하세요: ");

    if (sunteck <= 0 || sunteck > len(memory)) { //선택한 번호가 0보다 작거나 노드? 크기보다 크면 안됨
        println("잘못된 번호입니다.");
        return;
    }

    // 노드 삭제
    Node* sakjea = memory[sunteck - 1]; // 인덱스 조정
    if (sakjea == head) { // 삭제할 데이터가 헤드인 경우
        head = head->link; // head를 헤드가 링크하고 있는 곳으로 옮김
    }
    else {
        Node* pre = head; // pre는 삭제할 데이터의 바로 앞 데이터를 가리키기 위해 head로 초기화
        while (pre->link != sakjea) { // pre가 가리키는 링크가 삭제할 데이터와 같아질 때까지 반복
            pre = pre->link;
        }
        pre->link = sakjea->link; // 삭제할 데이터 연결 끊기
    }

    // 메모리에서 삭제할 노드를 제거
    auto it = find(memory.begin(), memory.end(), sakjea);
    if (it != memory.end()) {
        memory.erase(it);
    }
    /*연속으로 헤더 데이터를 삭제하니 비정상 적으로 종료됨.
    만약 delete sakjea가 호출되면 그노드는 메모리에서 해제되지만,
    그 노드에 대한 포인터가 여전히 memory에 남아있으면, 나중에
    그 포인터를 참조할 때 접근 위반이 발생할 수 있다고 함*/

    /*auto 쪽 설명
    find는 특정 값을 찾기위해 사용됨 memory 벡터에서
    sakjea가 가르키는 노드를 찾기위해서
    begin은 시작 end는 끝을 반환하고 sakjea는 찾고자하는 노드 포인터
    auto는 변수를 선언할때 그 타입을 컴파일러가 자동으로 유추하도록*/

    /*결론은 memory에서 sakjea를 찾음 시작과 끝에서 it으로 정의.
    erase 함수로 주어진것이 가리키는 요소를 memory벡터에서 삭제
    (메모리가 안전하게 관리 된다고 함!)*/

    println("노드가 삭제되었습니다.");
}


void insertNode(int wichi, string name, string phone) {
    // 전화번호 중복 체크
    for (Node* current = head; current != NULL; current = current->link) { //추가랑 똑같음
        if (current->phone == phone) {
            println("전화번호가 중복입니다. 삽입할 수 없습니다.");
            return;
        }
    }

    Node* node = new Node;
    node->name = name;
    node->phone = phone;

    if (wichi == 0) {   //맨앞를 골랐다면
        node->link = head;
        head = node; // head에 삽입
    }
    else {              //맨 앞이 아니라면
        Node* current = head;
        // wichi-1 인 이유는 내가 고른곳의 전이여야하기때문에 전의 데이터의 링크를 삽입한 데이터링크로 바꿀려고
        // 고른 위치까지 current를 옮긴다고 생각해야함
        for (int i = 0; i < wichi - 1 && current != NULL; i++) {
            current = current->link;
        }

        if (current == NULL) {
            println("잘못된 위치입니다.");
            delete node;            //만일 잘못된 위치를 입력했다면 쓸모없는 것을 가져왔기 때문에 삭제해 줘야함
            return;
        }
        node->link = current->link; //내가 추가한 노드의 링크가 지금 커런트가 링크하고 있는것으로
        current->link = node; // 중간에 삽입
    }
    memory.push_back(node);
    println("노드가 삽입되었습니다.");
}

void searchAll() {
    if (head == NULL) { //데이터가 하나도 없으면
        println("검색할 데이터가 없습니다.");
        return;
    }

    println("전체 노드:");
    Node* current = head;
    while (current != NULL) {
        print("{ " << current->name << ", " << current->phone << " } ");
        current = current->link;
    }
    println("");
}

//핸드폰 번호로 입력하기
void searchByPhone(string phone) {
    if (head == NULL) {
        println("검색할 데이터가 없습니다.");
        return;
    }

    int find = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->phone == phone) {
            println("검색 결과:");
            println("{ " << current->name << ", " << current->phone << " }");
            find++; //만약 전화번호로 찾았다면 find를 올려서 밑에 if 문을 실행하지 않게.
                    //여기 if 문밑에 else로 하는 방법 더 생각해보기..
        }
        current = current->link;
    }
    if (find == 0) {
        println("전화번호를 찾을 수 없습니다.");
    }
}

void searchByName(string name) {
    if (head == NULL) {
        println("검색할 데이터가 없습니다.");
        return;
    }

    int find = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->name == name) {
            println("검색 결과:");
            println("{ " << current->name << ", " << current->phone << " }");
            find++;
        }
        current = current->link;
    }
    if (find == 0) {
        println("이름을 찾을 수 없습니다.");
    }
}

void freeMemory() { // 할당된 모든 노드의 메모리를 해제한다.
    for (int i = 0; i < len(memory); i++)
        delete memory[i];
}

int main() {
    int sunteck;
    string name, phone;

    while (true) {
        println("1. 추가");
        println("2. 삭제");
        println("3. 삽입");
        println("4. 전체 검색");
        println("5. 전화번호 검색");
        println("6. 이름 검색");
        println("7. 종료");
        input(sunteck, "원하는 작업을 선택하세요: ");

        switch (sunteck) {
        case 1:
            input(name, "이름을 입력하세요: ");
            input(phone, "전화번호를 입력하세요: ");
            addNode(name, phone);
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            if (head == NULL) {
                println("데이터가 없습니다. 삽입할 수 없습니다.");
                break;
            }
            int wichi;
            println("삽입할 위치를 입력하세요:");
            searchAll();
            input(wichi, "위치: ");
            input(name, "이름을 입력하세요: ");
            input(phone, "전화번호를 입력하세요: ");
            insertNode(wichi, name, phone);
            break;
        case 4:
            searchAll();
            break;
        case 5:
            input(phone, "전화번호를 입력하세요: ");
            searchByPhone(phone);
            break;
        case 6:
            input(name, "이름을 입력하세요: ");
            searchByName(name);
            break;
        case 7:
            println("프로그램을 종료합니다.");
            freeMemory();
            return 0;
        default:
            println("잘못된 선택입니다.");
            break;
        }
    }
}
