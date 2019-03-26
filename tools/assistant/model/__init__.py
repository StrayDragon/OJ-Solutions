from abc import ABCMeta, abstractmethod


class Serializable(metaclass=ABCMeta):
    @abstractmethod
    def to_json(self) -> dict:
        pass

    @classmethod
    def from_json(cls, json_obj: dict):
        # TODO:如何编写反序列化
        pass
