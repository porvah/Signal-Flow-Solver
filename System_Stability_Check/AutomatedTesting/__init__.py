
import os
import sys



paths = ['./System_Stability_Check']
for path in paths:
    abs_path = os.path.abspath(path)
    print(f"Original path: {path}, Absolute path: {abs_path}")
    if abs_path not in sys.path:
        sys.path.append(abs_path)

from Engine.engine import RoutheEngine
from InputGenerator import InputGenerator
from Checker import Checker