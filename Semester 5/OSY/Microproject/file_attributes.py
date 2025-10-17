import os
import sys
import time
from datetime import datetime
from stat import *

def get_human_readable_size(size_in_bytes):
    for unit in ['bytes', 'KB', 'MB', 'GB', 'TB']:
        if size_in_bytes < 1024.0:
            return f"{size_in_bytes:.2f} {unit}" if unit != 'bytes' else f"{size_in_bytes} {unit}"
        size_in_bytes /= 1024.0
    return f"{size_in_bytes:.2f} PB"

def get_file_attributes(file_path):
    try:
        # Get the file statistics
        stats = os.stat(file_path)
        
        # Get file permissions in octal format
        permissions = str(oct(stats.st_mode & 0o777))[2:]  # Remove '0o' prefix
        
        # Get human-readable timestamps
        creation_time = datetime.fromtimestamp(stats.st_ctime)
        modified_time = datetime.fromtimestamp(stats.st_mtime)
        access_time = datetime.fromtimestamp(stats.st_atime)
        
        # Print all available metadata
        print(f"\nFile Attributes for: {file_path}")
        
        print("-" * 50)

        print(f"Size: {stats.st_size} bytes ({get_human_readable_size(stats.st_size)})")
        print(f"Creation Time: {creation_time}")
        print(f"Last Modified: {modified_time}")
        print(f"Last Accessed: {access_time}")
        
        print("-" * 50)
        
        print(f"Permissions: {permissions} ({get_permission_string(stats.st_mode)})")
        print(f"Owner ID: {stats.st_uid}")
        print(f"Group ID: {stats.st_gid}")
        print(f"Device ID: {stats.st_dev}")
        
        print("-" * 50)
        print(f"Number of Hard Links: {stats.st_nlink}")
        print(f"Inode Number: {stats.st_ino}")
        print("")
        
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found")
    except Exception as e:
        print(f"Error: {str(e)}")

def get_permission_string(mode):
    perms = []
    
    # User permissions
    perms.append('r' if mode & S_IRUSR else '-')
    perms.append('w' if mode & S_IWUSR else '-')
    perms.append('x' if mode & S_IXUSR else '-')
    
    # Group permissions
    perms.append('r' if mode & S_IRGRP else '-')
    perms.append('w' if mode & S_IWGRP else '-')
    perms.append('x' if mode & S_IXGRP else '-')
    
    # Other permissions
    perms.append('r' if mode & S_IROTH else '-')
    perms.append('w' if mode & S_IWOTH else '-')
    perms.append('x' if mode & S_IXOTH else '-')
    
    return ''.join(perms)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python file_attributes.py <file_path>")
        sys.exit(1)
    
    file_path = sys.argv[1]
    get_file_attributes(file_path)
