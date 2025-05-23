# [Platinum V] 1 또는 -1 - 1635 

[문제 링크](https://www.acmicpc.net/problem/1635) 

### 성능 요약

메모리: 2020 KB, 시간: 116 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2025년 4월 22일 13:29:58

### 문제 설명

<p>1 또는 -1로 이루어진 길이 N의 수열이 있다.예를 들어 N이 4인 경우, {-1, 1, -1, -1} 또는 {1, 1, -1, 1} 등이 이에 해당된다.</p>

<p>수열을 이루고 있는 모든 수들의 합을 "수열값"이라고 한다. 위에서 예로 든 {-1, 1, -1, -1} 의 수열값은 -2, {1, 1, -1, 1} 의 수열값은 2이다.</p>

<p>두 수열의 곱을 다음과 같이 정의해볼 수 있다. 수열을 이루는 수들을 차례로 곱하는 것이다. 예를 들어 {-1, 1, -1, -1} 과 {1, 1, -1, 1} 의 곱은 {-1, 1, 1, -1} 이 되는 것이다. 곱셈을 통해 만들어진 이 수열의 수열값은 0이 된다.</p>

<p>M개의 수열 a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>N</sub>이 주어졌다. 각각의 a<sub>i</sub>는 1 또는 -1로 이루어진 길이 N인 수열이다. 이때, 모든 수열 에 대해 적절히 대응되는 수열 b<sub>i</sub>를 찾아, 두 수열을 곱한 결과 나타나는 수열의 수열값이 0이 되도록 하려고 한다. 즉, a<sub>i</sub>가 {-1, 1, -1, -1} 일 때, 위의 조건을 만족하는 b<sub>i</sub>로는 {1, 1, -1, 1}, {1, -1, -1, -1} 등이 있다.</p>

<p>단순히 M개의 bi를 구하는 것은 그리 어려운 일이 아니다. 따라서 우리는 N개 이하의 수열만을 가지고 모든 b<sub>i</sub>를 표현하려 한다. 즉 수열 b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>M</sub>중 중복되는 것을 제외하고 서로 다른 것들의 개수가 N개 이하가 되도록 모든 b<sub>i</sub>들을 만들고 싶다.</p>

<p>M개의 수열이 주어졌을 때, N개 이하 종류의 수열을 이용하여 조건을 만족하는 b<sub>i</sub>들을 찾는 프로그램을 작성하시오. N이 홀수인 경우 수열값이 0이 되지 않으므로, N이 짝수인 경우만을 생각하기로 한다.</p>

### 입력 

 <p>첫째 줄에 두 정수 N과 M이 빈 칸을 사이에 두고 주어진다. (2 ≤ N ≤ 100, N은 짝수, 1 ≤ M ≤ 10,000) 이어서 M개의 줄에 걸쳐 수열 a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>N</sub>이 한 줄에 하나씩 주어진다. 각 줄에는 1 또는 -1의 정수가 빈 칸을 사이에 두고 N개씩 주어지게 된다.</p>

### 출력 

 <p>첫째 줄부터 M개의 줄에 걸쳐 구하고자 하는 수열 b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>M</sub>을 한 줄에 하나씩 출력한다. 즉 각 줄에 1 또는 -1의 정수를 빈 칸을 사이에 두고 N개씩 출력해야 한다. 반드시 N개 이하의 수열만을 가지고 모든 b<sub>i</sub>가 표현되어야 한다. 답이 여러 가지일 수 있으므로 아무 것이나 하나 출력하면 된다. 항상 가능한 경우만이 입력으로 주어진다.</p>

