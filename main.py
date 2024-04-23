from typing import Union

from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()


class Iti(BaseModel):
    name: str
    price: float
    is_offer: Union[bool, None] = None


@app.get("/")
def read_root():
    return {"Hello": "folks"}


@app.get("/iti/{item_id}")
def read_item(item_id: int, q: Union[str, None] = None):
    return {"item_id": item_id, "q": q}


@app.put("/iti/{item_id}")
def update_item(item_id: int, item: Iti):
    return {"item_name": item.name, "item_id": item_id}