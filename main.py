class SparseMatrix:
    def __init__(self) -> None:
        self.matrix = {}

    def add_pincode(self, merchant, pincode):
        if pincode in self.matrix:
            self.matrix[pincode].add(merchant)
        else:
            self.matrix[pincode] = {merchant}

    def check_pincode(self, merchant, pincode):
        return (pincode in self.matrix) and (merchant in self.matrix[pincode])

    def remove_pincode(self, merchant, pincode):
        assert self.check_pincode(merchant, pincode), "No such pincode exists for the merchant"
        self.matrix[pincode].remove(merchant)