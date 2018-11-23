# File : word_frequency.py
# Author : 임현 (hyunzion@gmail.com)
# Since : 2018 - 06 - 06

import string	# 스트링
import re		# 정규 표현식

# 단어 빈도수를 저장할 파이썬 딕셔너리 변수
frequency = {}

# sms spam data txt 파일을 염
spam_data = open('spam_sms.txt', 'r')

# data를 읽어서 문자를 모두 소문자로 바꿔줌 (정규 표현식을 쉽게 쓰기 위함)
data_string = spam_data.read().lower()
# a부터 z까지 해당되는 정규 표현식, 3글자 이상 20글자 이하
match_pattern = re.findall(r'\b[a-z]{3,20}\b', data_string)

# 단어 빈도수 카운트
for word in match_pattern:
	count = frequency.get(word, 0)
	frequency[word] = count + 1

# 총 단어 갯수 변수
cnt = 0

# 단어 빈도수 70이상만 출력
for words in frequency.keys():
	if frequency.get(words) > 70:
		print(words, frequency[words]) # 각 단어 및 빈도수 출력
		cnt = cnt + frequency[words]

# 총 단어 갯수 출력
print(cnt)

