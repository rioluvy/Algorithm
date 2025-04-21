# [Gold IV] Hexagram - 4082 

[문제 링크](https://www.acmicpc.net/problem/4082) 

### 성능 요약

메모리: 2020 KB, 시간: 1976 ms

### 분류

백트래킹

### 제출 일자

2025년 4월 21일 20:42:35

### 문제 설명

<p>A Hexagram is a 6-pointed star, sometimes called the Star of David. Given these numbers:</p>

<pre>3 17 15 18 11 22 12 23 21 7 9 13</pre>

<p>There are four unique ways of assigning the numbers to vertices of the hexagram such that all of the sets of four numbers along the lines have the same sum (57 in this case). All other ways may be obtained from these by rotation and/or reflection.</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/4082/1.png" style="height:157px; width:587px"></p>

<p>Given 12 distinct numbers, in how many ways, disregarding rotations and reflections, can you assign the numbers to the vertices such that the sum of the numbers along each of 6 straight lines passing through 4 vertices is the same?</p>

### 입력 

 <p>There will be several test cases in the input. Each test case will consist of twelve unique positive integers on a single line, with single spaces separating them. All of the numbers will be less than 1,000,000. The input will end with a line with twelve 0s.</p>

### 출력 

 <p>For each test case, output the number of ways the numbers can be assigned to vertices such that the sum along each line of the hexagram is the same. Put each answer on its own line. Output no extra spaces, and do not separate answers with blank lines.</p>

