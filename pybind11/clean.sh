rm -rf .pytest_cache build dist *.egg-info
find . -name '*.so' -exec rm -f {} \;
find . -name '__pycache__' -exec rm -rf {} \;
