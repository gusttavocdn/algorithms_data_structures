class Node<T> {
	public data;
	public next: Node<T> | null;

	constructor(data: T) {
		this.data = data;
		this.next = null;
	}
}

export default class SinglyLinkedList<T> {
	public length: number;
	protected head: Node<T> | null;

	constructor() {
		this.head = null;
		this.length = 0;
	}

	prepend(item: T): void {
		const newHead = new Node(item);
		// makes the swap to make the new Item the head of the list.
		[newHead.next, this.head] = [this.head, newHead];
		this.length += 1;
	}

	insertAt(item: T, idx: number): void {
		if (idx === 0) this.prepend(item);

		let prevNode = this.head as Node<T>;
		let currentNode = prevNode.next;
		let i = 1;

		while (currentNode !== null && i < idx) {
			prevNode = currentNode;
			currentNode = currentNode.next;
			i++;
		}

		const newNode = new Node(item);
		prevNode.next = newNode;
		newNode.next = currentNode;
		this.length += 1;
	}

	append(item: T): void {
		if (this.head === null) {
			this.head = new Node(item);
			this.length = 1;
			return;
		}

		let currentNode = this.head;
		while (currentNode.next !== null) {
			currentNode = currentNode.next;
		}

		currentNode.next = new Node(item);
		this.length += 1;
	}

	remove(item: T): T | undefined {
		if (this.head?.data === item) {
			const removedValue = this.head.data;
			this.head = this.head.next;
			this.length -= 1;
			return removedValue;
		}

		let prevNode = this.head as Node<T>;
		let currentNode = prevNode.next;

		while (currentNode !== null) {
			if (currentNode.data === item) {
				prevNode.next = currentNode.next;
				const removedValue = currentNode.data;
				this.length -= 1;
				return removedValue;
			}
			prevNode = currentNode;
			currentNode = currentNode.next;
		}

		return undefined;
	}

	get(idx: number): T | undefined {
		let i = 0;
		let currentNode = this.head;

		while (i < idx && currentNode !== null) {
			currentNode = currentNode.next;
			i++;
		}
		return currentNode?.data;
	}

	removeAt(idx: number): T | undefined {
		if (idx === 0) {
			if (this.head === null) return undefined;

			const removedValue = this.head.data;
			this.head = this.head.next;
			this.length -= 1;
			return removedValue;
		}

		let i = 0;
		let prevNode: Node<T> = null as any;
		let currentNode = this.head as Node<T>;

		while (i < idx && currentNode.next !== null) {
			prevNode = currentNode;
			currentNode = currentNode.next;
			i++;
		}
		prevNode.next = currentNode.next;
		this.length -= 1;
		return currentNode.data;
	}
}

// const list = new SinglyLinkedList<number>();
// list.append(5);
// list.append(7);
// list.append(9);
// list.insertAt(131, 5);
// console.log(list.length);
// console.log(list)
