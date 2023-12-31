#! /bin/bash
python3 -m venv /workspace/testing_env
source /workspace/testing_env/bin/activate
python3 -m pip install --upgrade pip
# python3 -m pip freeze > /workspace/edx_labs/source/lecture_6/requirements.txt
python3 -m pip install -r /workspace/edx_labs/source/lecture_6/requirements.txt