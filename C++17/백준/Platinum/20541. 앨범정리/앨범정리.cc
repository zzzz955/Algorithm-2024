#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

struct Data { // 폴더 정보를 저장할 구조체
	string par; // 부모 폴더명
	string cur; // 현재 폴더명
	set<string> albums; // 현재 폴더에 존재하는 하위 폴더명의 집합
	set<string> photos; // 현재 폴더에 존재하는 사진명의 집합
};

unordered_map<string, Data> dic;
int del_album = 0, del_photo = 0; // 삭제 정보 저장용

void dfs(string s) { // 폴더 삭제 시 진행할 재귀, 현재 폴더명을 매개변수로 받는다.
	set<string>& albums = dic[s].albums; // 현재 폴더의 하위 폴더 집합
	set<string>& photos = dic[s].photos; // 현재 폴더의 사진 집합
	del_album += albums.size(); // 폴더의 개수만큼 더해준다.
	del_photo += photos.size(); // 사진의 개수만큼 더해준다.
	for (string album : albums) dfs(album); // 하위 폴더 재귀 진행
	dic.erase(s); // 현재 폴더를 맵에서 삭제
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string cur = "album"; // 루트 폴더
	dic[cur] = { "album", "album", {}, {} }; // 루트 폴더의 부모는 자기 자신
	int q; cin >> q;
	while (q--) {
		string order, arg; cin >> order >> arg; // 명령어, 쿼리
		if (order == "mkalb") { // 1. 폴더 생성
			set<string>& albums = dic[cur].albums; // 현재 폴더 정보 참조
			if (albums.find(cur + arg) == albums.end()) { // 현재 폴더에 생성하고자 하는 폴더가 없으면
				albums.insert(cur + arg); // 폴더 추가 (폴더 명 : 현재 폴더 + 폴더 명)
				dic[cur + arg] = { cur, arg, {}, {} }; // 생성된 폴더 초기화
			}
			else cout << "duplicated album name\n"; // 중복 존재 시
		}
		else if (order == "rmalb") { // 2. 폴더 삭제
			del_album = 0, del_photo = 0; // 초기값 할당
			set<string>& albums = dic[cur].albums; // 현재 폴더 정보 참조
			if (arg == "-1" && !albums.empty()) { // 사전순 가장 앞쪽 폴더 삭제
				string tar = *albums.begin();
				dfs(tar); // 해당 폴더의 하위 폴더 삭제
				albums.erase(tar); // 현재 폴더에서 해당 폴더 삭제
				dic.erase(tar); // 맵에서 해당 폴더 삭제
				del_album++; // 폴더를 하나 지웠다.
			}
			else if (arg == "1" && !albums.empty()) { // 사전순 가장 뒤족 폴더 삭제
				string tar = *albums.rbegin();
				dfs(tar);
				albums.erase(tar);
				dic.erase(tar);
				del_album++;
			}
			else if (arg == "0" && !albums.empty()) { // 현재 폴더의 모든 폴더 삭제
				del_album += albums.size();
				for (string album : albums) {
					dfs(album);
					dic.erase(album);
				}
				albums.clear();
			}
			else { // 특정 폴더 삭제
				if (albums.find(cur + arg) != albums.end()) { // 해당 폴더명이 있는지 체크
					string tar = cur + arg;
					dfs(tar);
					albums.erase(tar);
					del_album++;
				}
			}
			cout << del_album << " " << del_photo << "\n"; // 삭제한 폴더 및 사진 파일 개수 출력
		}
		else if (order == "insert") { // 사진을 현재 폴더에 추가한다.
			set<string>& photos = dic[cur].photos;
			if (photos.find(cur + arg) == photos.end()) photos.insert(cur + arg); // 중복 여부 체크
			else cout << "duplicated photo name\n"; // 중복 시 출력
		}
		else if (order == "delete") { // 현재 폴더에서 특정 사진을 삭제한다.
			del_photo = 0; // 삭제한 개수 초깃값
			set<string>& photos = dic[cur].photos;
			if (arg == "-1") { // 사전순 가장 앞쪽 사진 삭제
				if (!photos.empty()) {
					photos.erase(photos.begin());
					del_photo++;
				}
			}
			else if (arg == "1") { // 사전순 가장 뒤쪽 사진 삭제
				if (!photos.empty()) {
					photos.erase(--photos.end());
					del_photo++;
				}
			}
			else if (arg == "0") { // 존재하는 모든 사진 삭제
				del_photo = photos.size();
				photos.clear();
			}
			else { // 특정 이름의 사진 삭제
				if (photos.find(cur + arg) != photos.end()) { // 존재하는지 여부 체크
					photos.erase(cur + arg);
					del_photo++;
				}
			}
			cout << del_photo << "\n"; // 삭제한 개수 출력
		}
		else { // 폴더 이동
			if (arg == "..") cur = dic[cur].par; // 상위 폴더로 이동
			else if (arg == "/") cur = "album"; // 루트 폴더로 이동
			else { // 현재 폴더에 존재하는 특정 폴더로 이동
				set<string>& albums = dic[cur].albums;
				if (albums.find(cur + arg) != albums.end()) cur = cur + arg;
			}
			cout << dic[cur].cur << "\n"; // 이동 작업 후 현재 폴더의 이름 출력
		}
	}
}