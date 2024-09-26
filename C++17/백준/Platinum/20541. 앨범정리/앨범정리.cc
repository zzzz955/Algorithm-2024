#include<iostream>
#include<unordered_map>
#include<set>

using namespace std;

struct Data { // 앨범 정보를 저장할 구조체
	string par; // 부모 앨범명
	string cur; // 현재 앨범명
	set<string> albums; // 현재 앨범에 존재하는 하위 앨범명의 집합
	set<string> photos; // 현재 앨범에 존재하는 사진명의 집합
};

unordered_map<string, Data> dic;
int del_album = 0, del_photo = 0; // 삭제 정보 저장용

void dfs(string s) { // 앨범 삭제 시 진행할 재귀, 현재 앨범명을 매개변수로 받는다.
	set<string>& albums = dic[s].albums; // 현재 앨범의 하위 앨범 집합
	set<string>& photos = dic[s].photos; // 현재 앨범의 사진 집합
	del_album += albums.size(); // 앨범의 개수만큼 더해준다.
	del_photo += photos.size(); // 사진의 개수만큼 더해준다.
	for (string album : albums) dfs(album); // 하위 앨범 재귀 진행
	dic.erase(s); // 현재 앨범를 맵에서 삭제
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string cur = "album"; // 루트 앨범
	dic[cur] = { "album", "album", {}, {} }; // 루트 앨범 초기화, 부모는 자기 자신
	int q; cin >> q;
	while (q--) {
		string order, arg; cin >> order >> arg; // 명령어, 쿼리
		string new_path = cur + arg; // 새로운 경로, 현재 폴더명 + 입력값 (입력값이 S일때만 사용)
		Data& data = dic[cur]; // 현재 앨범 참조
		if (order == "mkalb") { // 1. 앨범 생성
			set<string>& albums = data.albums; // 현재 앨범 정보 참조
			if (albums.find(new_path) == albums.end()) { // 현재 앨범에 생성하고자 하는 앨범이 없으면
				albums.insert(new_path); // 앨범 추가 (앨범 명 : 현재 앨범 + 앨범 명)
				dic[new_path] = { cur, arg, {}, {} }; // 생성된 앨범 초기화
			}
			else cout << "duplicated album name\n"; // 중복 존재 시
		}
		else if (order == "rmalb") { // 2. 앨범 삭제
			del_album = 0, del_photo = 0; // 초기값 할당
			set<string>& albums = data.albums; // 현재 앨범 정보 참조
			if (!albums.empty()) { // 앨범이 있을때
				del_album = 1; // 기본 1개 삭제
				if (arg == "-1") { // 사전순 가장 앞쪽 앨범 삭제
					string tar = *albums.begin();
					dfs(tar); // 해당 앨범의 하위 앨범 삭제
					albums.erase(tar); // 현재 앨범에서 해당 앨범 삭제
					dic.erase(tar); // 맵에서 해당 앨범 삭제
				}
				else if (arg == "1") { // 사전순 가장 뒤족 앨범 삭제
					string tar = *albums.rbegin();
					dfs(tar);
					albums.erase(tar);
					dic.erase(tar);
				}
				else if (arg == "0") { // 현재 앨범의 모든 앨범 삭제
					del_album = albums.size(); // 삭제한 개수 최신화
					for (string album : albums) {
						dfs(album);
						dic.erase(album);
					}
					albums.clear(); // 앨범 초기화
				}
				else { // 특정 앨범 삭제
					if (albums.find(new_path) != albums.end()) { // 해당 앨범명이 있는지 체크
						dfs(new_path);
						albums.erase(new_path);
						dic.erase(new_path);
					}
					else del_album = 0; // 일치하는 앨범이 없으면 삭제한 개수 0으로 변경
				}
			}
			cout << del_album << " " << del_photo << "\n"; // 삭제한 앨범 및 사진 파일 개수 출력
		}
		else if (order == "insert") { // 사진을 현재 앨범에 추가한다.
			set<string>& photos = data.photos;
			if (photos.find(new_path) == photos.end()) photos.insert(new_path); // 중복 여부 체크
			else cout << "duplicated photo name\n"; // 중복 시 출력
		}
		else if (order == "delete") { // 현재 앨범에서 특정 사진을 삭제한다.
			del_photo = 0; // 삭제한 개수 초깃값
			set<string>& photos = data.photos;
			if (!photos.empty()) { // 사진이 있을때
				del_photo = 1; // 기본 1개 삭제
				if (arg == "-1") photos.erase(photos.begin()); // 사전순 가장 앞쪽 사진 삭제
				else if (arg == "1") photos.erase(--photos.end()); // 사전순 가장 뒤쪽 사진 삭제
				else if (arg == "0") { // 존재하는 모든 사진 삭제
					del_photo = photos.size(); // 삭제한 개수 최신화
					photos.clear();
				}
				else { // 특정 이름의 사진 삭제
					if (photos.find(new_path) != photos.end()) photos.erase(new_path); // 존재하는지 여부 체크
					else del_photo = 0; // 일치하는 사진이 없으면 삭제한 개수 0으로 변경
				}
			}
			cout << del_photo << "\n"; // 삭제한 개수 출력
		}
		else { // 앨범 이동
			if (arg == "..") cur = data.par; // 상위 앨범로 이동
			else if (arg == "/") cur = "album"; // 루트 앨범로 이동
			else { // 현재 앨범에 존재하는 특정 앨범로 이동
				set<string>& albums = data.albums;
				if (albums.find(new_path) != albums.end()) cur = new_path;
			}
			cout << dic[cur].cur << "\n"; // 이동 작업 후 현재 앨범의 이름 출력
		}
	}
}