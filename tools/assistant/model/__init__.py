from abc import abstractmethod, ABC


class Serializable(ABC):
    @abstractmethod
    def to_json(self) -> dict:
        pass

    @classmethod
    @abstractmethod
    def from_json(cls, json_obj: dict):
        pass
