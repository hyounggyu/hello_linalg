# Simple Linear Algebra Examples in PyO3

PyO3를 이용한 Python 패키지 개발

`pipx` 설치 

```
brew install pipx
```

PATH 업데이트

```
pipx ensurepath
```

`maturin` 설치

```
pipx install maturin
```

`linalg` 프로젝트 시작

```
maturin new linalg
✔ 🤷 Which kind of bindings to use?
  📖 Documentation: https://maturin.rs/bindings.html · pyo3
  ✨ Done! New project created linalg
```

Python 가상 환경 생성

```
conda create -n linalg python=3.11
```

개발용 빌드

```
cd linalg
maturin develop
```

Python에서 모듈 호출

```
>>> import linalg
>>> linalg.sum_as_string(3,4)
```
