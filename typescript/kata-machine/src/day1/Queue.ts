class QNode<T> {
	public data: T;
	public next: QNode<T> | null;

	constructor(item: T) {
		this.data = item;
		this.next = null;
	}
}

export default class Queue<T> {
	public length: number;
	public head: QNode<T> | null;
	public tail: QNode<T> | null;

	constructor() {
		this.head = this.tail = null;
		this.length = 0;
	}

	enqueue(item: T): void {
		const newNode = new QNode(item);

		this.length++;
		if (!this.head) {
			this.head = newNode;
			this.tail = newNode;
			return;
		}

		this.tail!.next = newNode;
		this.tail = newNode;
	}

	deque(): T | undefined {
		if (!this.head) return undefined;

		const removedNode = this.head;

		this.head = this.head!.next;
		this.length--;

		if (this.length === 0) this.tail = null;
		return removedNode?.data;
	}

	peek(): T | undefined {
		return this.head?.data;
	}
}
