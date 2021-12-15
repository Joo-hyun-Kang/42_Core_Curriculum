#  뭐하고 있는가?

## 이슈: 버퍼 사이즈로 잘라온 것에 줄바꿈이 없는 경우 널 반환해야 하는가? : 해결중...

#  get_next_line는 어떤 프로젝트인가?


#  어떻게 구현했는가?

## 이슈: 버퍼 사이즈로 잘라온 것에 줄바꿈이 없는 경우 널 반환해야 하는가? : 해결중...
* 버퍼 사이즈 < 줄바꿈 일때도 기존에 것을 기억했다가 나중에 줄바꿈이 나올 때까지 출력해야 함

## 이슈: 버퍼 사이즈가 굉장히 크게 덩어리로 가져올 때 바로 리드 하는 것이 아니라 리드 한 것에 남겨두기: 해결
* 버퍼 사이즈 >= 줄바꿈
	* 리드 하고 나서 남은 줄들을 새로운 줄 이전에 받아와야 함

## 이슈: read 함수가 gnl 함수 호출 뒤에도 여전히 그 다음 것을 읽어주는 지 : 해결
* read는 별도로 이동시켜주지 않아도 읽은 그 다음을 읽는다
### read 함수는 왜 그런지?

## 이슈: 왜 마지막에 널문자를 붙여주는지? : 해결
텍스트 데이터로 들어오기 때문에 거기까지 탐색해서 반환하려고


## 한글을 읽게끔 구현은?


# 왜? 
## read 함수 리턴 값
RETURN VALUES
     If successful, the number of bytes actually read is returned.  Upon reading end-of-file, zero is
     returned.  Otherwise, a -1 is returned and the global variable errno is set to indicate the error.

# 부가적인 지식
## 리눅스 출력 시 $는 줄바꿈 혹은 EOF, \n은 그냥 적는 건 특수문자가 아니라 텍스트일뿐
