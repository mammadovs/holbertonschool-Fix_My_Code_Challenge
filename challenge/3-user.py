#!/usr/bin/python3
"""
3-user.py: Fix User class password validation
"""


class User:
    """My User class"""

    def __init__(self):
        """:initialize user"""
        self.__password = None

    @property
    def password(self):
        """password getter"""
        return self.__password

    @password.setter
    def password(self, pwd):
        """password setter"""
        if pwd is None or not isinstance(pwd, str):
            self.__password = None
        else:
            import hashlib
            self.__password = hashlib.md5(pwd.encode()).hexdigest()

    def is_valid_password(self, pwd):
        """Validates the password"""
        if pwd is None or not isinstance(pwd, str):
            return False
        import hashlib
        hashed_pwd = hashlib.md5(pwd.encode()).hexdigest()
        return hashed_pwd == self.__password


if __name__ == "__main__":
    u = User()
    u.password = "Holberton"
    if u.is_valid_password("Holberton"):
        print("is_valid_password should return True if it's the right password")
    else:
        print("is_valid_password should return False if it's the wrong password")
        
