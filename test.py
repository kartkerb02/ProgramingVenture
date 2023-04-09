import pandas as pd  
import numpy as np


df = pd.read_csv("C:/Users/karti/Downloads/Responses.csv")

# df.sort_values(by="Entry Number ")
# print(df[df["Entry Number "] == "2020PH10676"])
conv = {
    "Entry Number " : str
}
df.astype(conv)
print(df.dtypes)